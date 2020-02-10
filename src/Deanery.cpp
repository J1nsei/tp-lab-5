#include "Deanery.h"

Deanery::Deanery(){
    this->studentCount = 0;
};

void Deanery::parseJson(string jsonFileName){
    ifstream ifs(jsonFileName);
    IStreamWrapper isw(ifs);
    Document d;
    d.ParseStream(isw);

    Group* curGr = nullptr;
    const Value& st = d["students"];
    const Value& gr = d["groups"];

    for(Value::ConstValueIterator itr = gr.Begin(); itr != gr.End(); ++itr){
        this->createGroup(itr->GetObject()["name"].GetString(),
                          itr->GetObject()["spec"].GetString());
    }
    cout<< "Groups created";

    for(Value::ConstValueIterator itr = st.Begin(); itr != st.End(); ++itr, this->studentCount++){
        curGr = this->findGroup(itr->GetObject()["group"].GetString());
        if(curGr != nullptr){
            curGr->addStudent(new Student(itr->GetObject()["name"].GetString(), this->studentCount));
        }
    }
    cout << " students added" << endl;
}

Group* Deanery::findGroup(string grName){
    int curNum = 0;
    for(vector<Group*>::iterator itr = this->groups.begin(); itr != this->groups.end(); ++itr, curNum++){
        if((*itr)->getTitle() == grName){
            return this->groups[curNum];
        }
    }
    return nullptr;
}

void Deanery::changeStGroup(Student* st, Group* newGroup){
    Student* temp = st;
    (st->getGroup())->deleteStudent(st);
    newGroup->addStudent(temp);
}

void Deanery::setHeads(){
    for(auto i: this->groups){
        i->assignHead();
    }
}

void Deanery::createJson(string jsonFileName){
    Document studJson;
    studJson.SetObject();
    Document::AllocatorType& alloc = studJson.GetAllocator();
    Value studArray(kArrayType);
    Value studObj(kObjectType);
    Value strCont;

    Value groupArray(kArrayType);
    Value groupObj(kObjectType);
    //подготовка для вывода в файл
    ofstream out(jsonFileName);
    //заполнение массива
    for(auto gr: this->groups){
        Value groupObj(kObjectType);
        strCont.SetString(gr->getTitle().c_str(), alloc);
        groupObj.AddMember("name", strCont, alloc);
        strCont.SetString(gr->getSpec().c_str(), alloc);
        groupObj.AddMember("spec", strCont, alloc);
        groupArray.PushBack(groupObj, alloc);
        for(auto st: gr->getStudList()){
            //обновляем объект
            Value studObj(kObjectType);
            //в объект добавляем имя и группу
            strCont.SetString(st->getName().c_str(),alloc);
            studObj.AddMember("name", strCont, alloc);
            strCont.SetString((st->getGroup())->getTitle().c_str(),alloc);
            studObj.AddMember("group", strCont, alloc);
            //добавляем объект в массив
            studArray.PushBack(studObj, alloc);
        }
    }
    //добавляем массив в документ
    studJson.AddMember("students", studArray, alloc);
    studJson.AddMember("groups", groupArray, alloc);
    //привязываем райтер к документу
    StringBuffer strbuf;
	PrettyWriter<StringBuffer> writer(strbuf);
	studJson.Accept(writer);
    //записываем json в файл
	out << strbuf.GetString() << endl;
	out.close();
}

void Deanery::addRandomMarks(){
    for(auto gr: this->groups){
        for(auto st: gr->getStudList()){
            for(int i = 0; i < 11; i++){
                st->addMark(rand()%11);
            }
        }
    }
}


void Deanery::deleteAllBadStudents(){
    for(auto gr: this->groups){
        for(auto st: gr->getStudList()){
            if(st->getMidMark() <= 3){
                gr->deleteStudent(st);
            }
        }
    }
    cout << "Bad Students Removed" << endl;
}

int Deanery::recieveStats(Group* group){
    if(group != nullptr){
        return group->getMidMark();
    }
    return -1;
}
int Deanery::recieveStats(Student* student){
    if(student != nullptr){
        for(auto gr: this->groups){
            return (gr->findStudent(student->getId()))->getMidMark();
        }
    }
    return -1;
}

void Deanery::createGroup(string name, string spec){
    this->groups.push_back(new Group(name));
    this->groups.back()->setSpec(spec);
}

void Deanery::resetIds(){
    int id = 0;
    for(auto i: this->groups){
        for(auto i2: i->getStudList()){
            i2->setId(id);
            id++;
        }
    }
}
