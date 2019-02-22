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

bool unique(long int ids[], int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (ids[i] == ids[j]) {
                return false;
            }
        }
    }
    return true;
}

int main(){

    srand(time(NULL));
    long id_list[200];
    cerr << "\t-----------------------------------\n";
    cerr << "\t-          Part A: Vectors        -\n";
    cerr << "\t-----------------------------------\n";

    cerr << "\n\t=========Test #1: Creating your Vector===========\n\n";

    Vector *vect = new Vector();
    assert(vect->size() == 0);
    cerr << "\n\t=========Test #1 Passed...            ===========\n\n";

    cerr << "\n\t=========Test #2: Inserting 20 Planets into your Vector===========\n\n";

    int i;
    for(i = 0; i < 20 ; i++){
        vect->insert(i, new Planet(0));
    }
    assert(vect->size() == 20);

    cerr << "\n\t=========Test #2 Passed...            ===========\n\n";

    cerr << "\n\t=========Test #3: Inserting values into out of bounds index===========\n\n";

    vect->insert(49, new Planet(0));
    assert(vect->size() == 50);
    vect->insert(40, new Planet(0));
    assert(vect->size() == 51);

    cerr << "\n\t=========Test #3 Passed...            ===========\n\n";

    cerr << "\n\t=========Test #4: Reading from your Vector===========\n\n";
    Planet * p;
    for(i = 0 ; i < 20 ; i++){
        p = vect->read(i);
        id_list[i] = p->getID();
    }
    assert(unique(id_list, i));
    //the new index of planet 20 will be 50 because the previous insert would increment the index
    p = vect->read(50);
    id_list[i++] = p->getID();
    p = vect->read(40);
    id_list[i++] = p->getID();
    assert(unique(id_list, i));
    cerr << "\n\t=========Test #4 Passed...            ===========\n\n";

    cerr << "\n\t=========Test #5: Reading from unititialized vector index (should return NULL)===========\n\n";

    assert(vect->read(45) == NULL);

    cerr << "\n\t=========Test #5 Passed...            ===========\n\n";

    cerr << "\n\t=========Test #6: Attempting to read from out of bounds===========\n\n";

    assert(vect->read(100) == NULL);

    cerr << "\n\t=========Test #6 Passed...            ===========\n\n";

    cerr << "\n\t=========Test #7: Remove elements from the vector ===========\n\n";

    //RemoveVector
    vect->remove(50);
    vect->remove(40);
    cerr << vect->size() << endl;
    assert(vect->size() == 49);
    cerr << "\n\t=========Test #7 Passed...            ===========\n\n";

    cerr << "\n\t=========Test #8: Remove elements from the vector randomly ===========\n\n";

    while(vect->size()){
        vect->remove((rand()%5));
    }
    vect->remove(50);

    cerr << "\n\t=========Test #8 Passed...            ===========\n\n";

    cerr << "\n\t=========Test #9: Delete the vector from memory ===========\n\n";

    delete vect;
    vect = NULL;

    cerr << "\n\t=========Test #9 Passed...            ===========\n\n";

    cerr << "\t-----------------------------------\n";
    cerr << "\t-          Part B: Lists        -\n";
    cerr << "\t-----------------------------------\n";

    cerr << "\n\t=========Test #10: Creating your Linked List===========\n\n";
    List * list = new List();

    cerr << "\n\t\tTest #10: Passed ...\n\n";

    cerr << "\n\t=========Test #11: Linked List Insertion===========\n\n";
    int index = 0;
    //add elements to the list
    for(int index = 0 ; index < 10 ; index++ ){
        list->insert(index, new Planet(0));
    }
    assert(list->size() == 10);
    //***** Test that out of bounds indexes are appended to the list ****/
    list->insert(20, new Planet(0));
    assert(list->size() == 11);

    cerr << "\n\t\tTest #11: Passed ...\n\n";

    cerr << "\n\t=========Test #12: Linked List Read===========\n\n";
    for(i = 0 ; i < 11 ; i++){
        p = list->read(i);
        id_list[i] = p->getID();
    }
    unique(id_list, 11);
    p = list->read(20);
    assert(p == NULL);
    cerr << "\n\t\tTest #12: Passed ...\n\n";

    cerr << "\n\t=========Test #13: Linked List Remove===========\n\n";

    for(index = 0; list->size() > 4; index++){
        index = index % 4;
        unsigned int s = list->size();
        list->remove(index);
        assert(list->size() == s-1);
    }
    assert(list->size() == 4);
    delete list;
    list = NULL;
    cerr << "\n\t\tTest #13 Passed...\n\n";

    cerr << "\n\t=========Test #14: Star Classes ===========\n\n";
    Starlist * sl = new Starlist();
    assert(sl->getCurrentNumPlanets() == 0);
    id_list[0] = sl->addPlanet();
    assert(sl->getCurrentNumPlanets() == 1);
    p = sl->getPlanet(id_list[0]);
    int pos = p->getPos();
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

    //add 200 more planets to each
    for(int i = 0; i < 200; i+=2){
        id_list[i] = sv->addPlanet();
        id_list[i+1] = sl->addPlanet();
    }
    //delete 10 random planets in the sun
    for(int i = 0; i < 50; i++){
        int rand_id = (rand() % (200));
        if(id_list[rand_id] == -1){
            continue;
        }else if(sv->removePlanet(id_list[rand_id]) ||
            sl->removePlanet(id_list[rand_id])){
            id_list[rand_id] = -1;
        }else{
            assert(false);
        }
    }

    sv->printStarInfo();
    sl->printStarInfo();

    cerr << "\n\t\tTest #14 Passed...\n\n";

    cerr << "\n\t=========Test #15: Star Delete ===========\n\n";
    delete sl;
    delete sv;
    cerr << "\n\t\tTest #15 Passed (but check valgrind to be sure)...\n\n";

    cerr << "Comparing performance of Vectors and Lists\n";
    sl = new Starlist();
    sv = new Starvector();

    struct timeval start, stop;
    float profile_time;

    /************************ Starvector Performance Test *********************/
    /** Testing performance of insert **/
    gettimeofday(&start, NULL);
    for(int i = 0; i < 200; i++){
        id_list[i] = sv->addPlanet();
    }
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starvector insert profile time = %lf\n", profile_time);

    /** Testing performance of read **/
    gettimeofday(&start, NULL);
    for(int i = 0; i < 200; i++){
        sv->getPlanet(id_list[i]);
    }
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starvector read profile time = %lf\n", profile_time);
    /** Testing performance of remove **/
    gettimeofday(&start, NULL);
    for(int i = 0; i < 200; i+=5){
        sv->removePlanet(id_list[i]);
    }
    delete sv;
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starvector remove profile time = %lf\n", profile_time);

    /************************ Starlist Performance Test *********************/
    /** Testing performance of insert **/
    gettimeofday(&start, NULL);
    for(int i = 0; i < 200; i++){
        id_list[i] = sl->addPlanet();
    }
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starlist insert profile time = %lf\n", profile_time);

    /** Testing performance of read **/
    gettimeofday(&start, NULL);
    for(int i = 0; i < 200; i++){
        sl->getPlanet(id_list[i]);
    }
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starlist read profile time = %lf\n", profile_time);
    /** Testing performance of remove **/
    gettimeofday(&start, NULL);
    for(int i = 0; i < 200; i+=5){
        sl->removePlanet(id_list[i]);
    }
    delete sl;
    gettimeofday(&stop, NULL);

    profile_time = ((stop.tv_sec* 1000000) + stop.tv_usec) - ((start.tv_sec* 1000000) + start.tv_usec);
    printf("\tCompleted Starlist remove profile time = %lf\n", profile_time);

    cerr << "\n\t========= Don't forget to submit your hash and check your code with Valgrind! ===========\n\n";
    return 0;
}
