#include "Star.h"
#include "Star.h"
#include "Planet.h"
#include "Planet.h"
#include "Vector.h"
#include "Vector.h"
#include "List.h"
#include "List.h"
#include <cassert>
#include <iostream>
#include <ctime>
#include <sys/time.h>

using namespace std;

bool unique(unsigned long int ids[], unsigned int size){
    for (unsigned int i = 0; i < size - 1; i++) {
        for (unsigned int j = i + 1; j < size; j++) {
            if (ids[i] == ids[j]) {
                return false;
            }
        }
    }
    return true;
}

int main(){

    srand(time(NULL));
    cerr << "\t-----------------------------------\n";
    cerr << "\t-          Part A: Vectors        -\n";
    cerr << "\t-----------------------------------\n";

#ifndef TEST1
{
    cerr << "\n\t=========Test #1: Creating your Vector===========\n\n";
    Vector *vect = new Vector();
    assert(vect->size() == 0);
    delete vect;
    cerr << "\n\tTest #1 Passed...\n\n";
}
#endif
#ifndef TEST2
{
    cerr << "\n\t=========Test #2: Inserting 20 Planets into your Vector===========\n\n";
    Vector *vect = new Vector();
    for(int i = 0; i < 20 ; i++){
        vect->insert(i, new Planet(0));
    }
    assert(vect->size() == 20);
    delete vect;
    cerr << "\n\tTest #2 Passed...\n\n";
}
#endif
#ifndef TEST3
{
    cerr << "\n\t=========Test #3: Inserting values into out of bounds index===========\n\n";
    Vector * vect = new Vector();
    for(int i = 0; i < 20 ; i++){
        vect->insert(i, new Planet(0));
    }
    vect->insert(49, new Planet(0));
    assert(vect->size() == 50);
    vect->insert(40, new Planet(0));
    assert(vect->size() == 51);
    delete vect;
    cerr << "\n\tTest #3 Passed...\n\n";
}
#endif
#ifndef TEST4
{
    cerr << "\n\t=========Test #4: Reading from your Vector===========\n\n";
    Vector *vect = new Vector();
    for(int i = 0; i < 20 ; i++){
        vect->insert(i, new Planet(0));
    }
    Planet * p;
    unsigned int id_list_size = 22;
    unsigned long id_list[id_list_size] = {0};
    for(unsigned int i = 0 ; i < id_list_size - 2 ; i++){
        p = vect->read(i);
        id_list[i] = p->getID();
    }
    assert(unique(id_list, id_list_size - 2));
    vect->insert(49, new Planet(0));
    vect->insert(40, new Planet(0));
    //the new index of planet 20 will be 50 because the previous insert would increment the index
    p = vect->read(50);
    id_list[20] = p->getID();
    p = vect->read(40);
    id_list[21] = p->getID();
    assert(unique(id_list, id_list_size));
    delete vect;
    cerr << "\n\tTest #4 Passed...\n\n";
}
#endif
#ifndef TEST5
{
    cerr << "\n\t=========Test #5: Reading from uninitialized vector index (should return NULL)===========\n\n";
    Vector *vect = new Vector();
    vect->insert(5, new Planet(0));
    for(int i = 0; i < 5; i++){
        assert(vect->read(0) == NULL);
    }
    delete vect;
    cerr << "\n\tTest #5 Passed...\n\n";
}
#endif
#ifndef TEST6
{
    cerr << "\n\t=========Test #6: Attempting to read from out of bounds===========\n\n";
    Vector *vect = new Vector();
    vect->insert(0, new Planet(0));
    assert(vect->read(100) == NULL);
    delete vect;
    cerr << "\n\tTest #6 Passed...\n\n";
}
#endif
#ifndef TEST7
{
    cerr << "\n\t=========Test #7: Remove elements from the vector ===========\n\n";
    Vector *vect = new Vector();
    for(int i = 0 ; i < 50; i++){vect->insert(i, new Planet(0));}
    assert(!vect->remove(51));
    assert(vect->remove(40));
    assert(vect->size() == 49);
    delete vect;
    cerr << "\n\tTest #7 Passed...\n\n";
}
#endif
#ifndef TEST8
{
    cerr << "\n\t=========Test #8: Remove elements from the vector randomly ===========\n\n";
    Vector *vect = new Vector();
    for(int i = 0 ; i < 50; i++){vect->insert(i, new Planet(0));}
    while(vect->size()){
        vect->remove((rand()%5));
    }
    delete vect;
    cerr << "\n\tTest #8 Passed...\n\n";
}
#endif
    cerr << "\t-----------------------------------\n";
    cerr << "\t-          Part B: Lists        -\n";
    cerr << "\t-----------------------------------\n";
#ifndef TEST9
{
    cerr << "\n\t=========Test #9: Creating your Linked List===========\n\n";
    List * list = new List();
    delete list;
    cerr << "\n\tTest #9: Passed ...\n\n";
}
#endif
#ifndef TEST10
{
    cerr << "\n\t=========Test #10: Linked List Insertion===========\n\n";
    List * list = new List();
    //add elements to the list
    for(int index = 0 ; index < 10 ; index++ ){
        list->insert(index, new Planet(0));
    }
    assert(list->size() == 10);
    //***** Test that out of bounds indexes are appended to the list ****/
    list->insert(20, new Planet(0));
    assert(list->size() == 11);
    delete list;
    cerr << "\n\tTest #10: Passed ...\n\n";
}
#endif
#ifndef TEST11
{
    cerr << "\n\t=========Test #11: Linked List Read===========\n\n";
    List * list = new List();
    unsigned int id_list_size = 10;
    unsigned long id_list[id_list_size];
    for(unsigned int i = 0 ; i < id_list_size ; i++ ){list->insert(i, new Planet(0));}
    for(unsigned int i = 0 ; i < id_list_size ; i++){
        Planet * p = list->read(i);
        id_list[i] = p->getID();
    }
    unique(id_list, id_list_size);
    Planet * p = list->read(20);
    assert(p == NULL);
    delete list;
    cerr << "\n\tTest #11: Passed ...\n\n";
}
#endif
#ifndef TEST12
{
    cerr << "\n\t=========Test #12: Linked List Remove===========\n\n";
    List * list = new List();
    unsigned int list_size = 40;
    for(unsigned int i = 0 ; i < list_size ; i++ ){list->insert(i, new Planet(0));}
    for(unsigned int index = 0; list->size() > 4; index++){
        index = index % 4;
        unsigned int s = list->size();
        list->remove(index);
        assert(list->size() == s-1);
    }
    assert(list->size() == 4);
    delete list;
    cerr << "\n\tTest #12 Passed...\n\n";
}
#endif
#ifndef TEST13
{
    cerr << "\n\t=========Test #13: Star Classes Create and Read ===========\n\n";
    Starlist * sl = new Starlist();
    unsigned int id_list_size = 2;
    unsigned long id_list[id_list_size];
    assert(sl->getCurrentNumPlanets() == 0);
    id_list[0] = sl->addPlanet();
    assert(sl->getCurrentNumPlanets() == 1);
    Planet * p = sl->getPlanet(id_list[0]);
    unsigned int pos = p->getPos();
    sl->orbit();
    assert(p->getPos() == (pos + 1) % 360);

    Starvector * sv = new Starvector();
    assert(sv->getCurrentNumPlanets() == 0);
    id_list[1] = sv->addPlanet();
    assert(sv->getCurrentNumPlanets() == 1);
    p = sv->getPlanet(id_list[1]);
    pos = p->getPos();
    sv->orbit();
    assert(p->getPos() == (pos + 1) % 360);
    delete sl;
    delete sv;
    cerr << "\n\tTest #13 Passed...\n\n";
}
#endif
#ifndef TEST14
{
    cerr << "\n\t=========Test #14: Star Classes Remove ===========\n\n";
    Starlist * sl = new Starlist();
    Starvector * sv = new Starvector();
    unsigned int id_list_size = 200;
    unsigned long id_list[id_list_size];
    //add 100 planets to each
    for(unsigned int i = 0; i < id_list_size; i+=2){
        id_list[i] = sv->addPlanet();
        id_list[i+1] = sl->addPlanet();
    }
    //delete random planets in the star classes
    for(unsigned int i = 0; i < id_list_size; i++){
        unsigned int rand_id = (rand() % (id_list_size));
        if(id_list[rand_id] == (unsigned) -1){
            continue;
        }else if(sv->removePlanet(id_list[rand_id]) || sl->removePlanet(id_list[rand_id])){
            id_list[rand_id] = (unsigned) -1;
        }else{
            assert(false);
        }
    }
    sv->printStarInfo();
    sl->printStarInfo();
    delete sl;
    delete sv;
    cerr << "\n\tTest #14 Passed (but check valgrind to be sure)...\n\n";
}
#endif
#ifndef TEST15
{
    cerr << "\n\t========='Test' #15: Relax ===========\n\n";
    cerr << "Comparing performance of Vectors and Lists\n";
    Starlist * sl = new Starlist();
    Starvector * sv = new Starvector();
    unsigned int id_list_size = 200;
    unsigned long id_list[id_list_size];
    struct timeval start, stop;
    float profile_time;

    /************************ Starvector Performance Test *********************/
    /** Testing performance of insert **/
    gettimeofday(&start, NULL);
    for(unsigned int i = 0; i < id_list_size; i++){
        id_list[i] = sv->addPlanet();
    }
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starvector insert profile time = %lf\n", profile_time);

    /** Testing performance of read **/
    gettimeofday(&start, NULL);
    for(unsigned int i = 0; i < id_list_size; i++){
        sv->getPlanet(id_list[i]);
    }
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starvector read profile time = %lf\n", profile_time);
    /** Testing performance of remove **/
    gettimeofday(&start, NULL);
    for(unsigned int i = 0; i < id_list_size; i+=rand()%5){
        sv->removePlanet(id_list[i]);
    }
    delete sv;
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starvector remove profile time = %lf\n", profile_time);

    /************************ Starlist Performance Test *********************/
    /** Testing performance of insert **/
    gettimeofday(&start, NULL);
    for(unsigned int i = 0; i < id_list_size; i++){
        id_list[i] = sl->addPlanet();
    }
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starlist insert profile time = %lf\n", profile_time);

    /** Testing performance of read **/
    gettimeofday(&start, NULL);
    for(unsigned int i = 0; i < id_list_size; i++){
        sl->getPlanet(id_list[i]);
    }
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starlist read profile time = %lf\n", profile_time);
    /** Testing performance of remove **/
    gettimeofday(&start, NULL);
    for(unsigned int i = 0; i < id_list_size; i+=5){
        sl->removePlanet(id_list[i]);
    }
    delete sl;
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starlist remove profile time = %lf\n", profile_time);

    cerr << "\n\t========= All tests complete. Don't forget to submit your hash and check your code with Valgrind! ===========\n\n";
}
#endif
    return 0;
}
