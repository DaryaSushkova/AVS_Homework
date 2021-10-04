#include "transport.h"
int In(transport* tr, FILE* in_file) {
    int speed;
    double distance;
    int count_of_value = fscanf(in_file, "%d %lf\n", &speed, &distance);
    if (count_of_value != 2) {
        return 1;
    }
    tr->speed = speed;
    tr->distance = distance;
    int type = 0;
    count_of_value = fscanf(in_file, "%d\n", &type);
    switch (type) {
        case 0:
            tr->type = transport::AIRPLANE;
            return In(&tr->arp, in_file);
        case 1:
            tr->type = transport::TRAIN;
            return In(&tr->trn, in_file);
        case 2:
            tr->type = transport::SHIP;
            return In(&tr->shp, in_file);
        default:
            return 1;
    }
}

void InRnd(transport* tr) {
    tr->speed = IntRnd(1, 1000);
    tr->distance = DoubleRnd(1, 20000);
    int type = IntRnd(0, 3);
    switch (type) {
        case 0:
            tr->type = transport::AIRPLANE;
            InRnd(&tr->arp);
            break;
        case 1:
            tr->type = transport::TRAIN;
            InRnd(&tr->trn);
            break;
        case 2:
            tr->type = transport::SHIP;
            InRnd(&tr->shp);
            break;
    }
}

void Out(const transport* tr, FILE* out_file) {
    switch (tr->type) {
        case transport::AIRPLANE:
            fprintf(out_file, "Airplane: range = %d, capacity = %d, speed = %d, way = %.2f, time = %.2f",
                    tr->arp.range_of_flight, tr->arp.lifting_capacity, tr->speed, tr->distance, GetTime(tr->speed, tr->distance));
            return;
        case transport::TRAIN:
            fprintf(out_file, "Train: cars = %d, speed = %d, way = %.2f, time = %.2f",
                    tr->trn.count_of_cars, tr->speed, tr->distance, GetTime(tr->speed, tr->distance));
            return;
        case transport::SHIP:
            fprintf(out_file, "Ship: displacement = %d, type = %s, speed = %d, way = %.2f, time = %.2f",
                    tr->shp.displacement, GetType(tr->shp.type), tr->speed, tr->distance, GetTime(tr->speed, tr->distance));
            return;
    }
}

double GetTime(int speed, double distance) {
    return distance / speed;
}
