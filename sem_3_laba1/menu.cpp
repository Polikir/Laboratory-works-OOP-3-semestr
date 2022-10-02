
#include <iostream>
using namespace std;


#include "Complex.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "SortFuncctions.h"



int ChooseTypeInput()
{
    int type;
    cout << "Select type of input: \n"
         << "\t1: By hand\n"
         << "\t2: Auto\n"
         << "\t0: Exit\n"
         << "Enter a number: ";
    cin >> type;
    return type;
}

void show_table(float im,float is,float dm,float ds,float rm,float rs)
{   cout<<"           ";//10
    cout<<"| Merge Sort |";//2+12
    cout<<" Shell Sort |"<<endl;//1+12
    cout<<" __________";//10
    cout<<"|____________|";//2+12
    cout<<"____________|"<<endl;//1+12

    cout<<"|increasing|";//10+2
    printf("  %f  ", im);
    printf("|  %f  |\n",is);

    cout<<"|decreasing|";//10+2
    printf("  %f  ", dm);
    printf("|  %f  |\n",ds);

    cout<<"|  random  |";//10+2
    printf("  %f  ", rm);
    printf("|  %f  |\n",rs);
}



int ChooseTypeSeq()
{
    int type;
    cout << "Select type of input: \n"
         << "\t1: int\n"
         << "\t2: float\n"
         << "\t3: complex\n"
         << "\t0: Exit\n"
         << "Enter a number: ";
    cin >> type;
    return type;
}

[[noreturn]] void MenuComprasion()
{
    while(true)
    {
        int function = ChooseTypeSeq();
        if (function == 0)
        {
            break;
        }
        if (function == 1)
        {
            int size,t;
            cout<<"Enter size - "<<endl;
            cin>>size;
            auto *seq_i = new ArraySequence<int>(size);
            auto *seq_d = new ArraySequence<int>(size);
            auto *seq_r = new ArraySequence<int>(size);
            auto *seq_i2 = new ArraySequence<int>(size);
            auto *seq_d2 = new ArraySequence<int>(size);
            auto *seq_r2 = new ArraySequence<int>(size);
            for (int i = 0; i < size; i++) {
                t = (1 + rand() % size);
                seq_i->Set(i,i);
                seq_d->Set(i,size-i);
                seq_r->Set(i, t);
                seq_i2->Set(i,i);
                seq_d2->Set(i,size-i);
                seq_r2->Set(i, t);
            }
            clock_t start = clock();
            sortMerge(seq_i,0,size-1);
            clock_t end = clock();
            double seconds_i_m = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortShell(seq_i2,size);
            end = clock();
            double seconds_i_s = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortMerge(seq_d,0,size-1);
            end = clock();
            double seconds_d_m = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortShell(seq_d2,size);
            end = clock();
            double seconds_d_s = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortMerge(seq_r,0,size-1);
            end = clock();
            double seconds_r_m = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortShell(seq_r2,size);
            end = clock();
            double seconds_r_s = (double)(end - start) / CLOCKS_PER_SEC;

            show_table(seconds_i_m,seconds_i_s,seconds_d_m,seconds_d_s,seconds_r_m,seconds_r_s);
        }
        else if (function == 2)
        {
            int size;
            float t;
            cout<<"Enter size - "<<endl;
            cin>>size;
            auto *seq_i = new ArraySequence<float>(size);
            auto *seq_d = new ArraySequence<float>(size);
            auto *seq_r = new ArraySequence<float>(size);
            auto *seq_i2 = new ArraySequence<float>(size);
            auto *seq_d2 = new ArraySequence<float>(size);
            auto *seq_r2 = new ArraySequence<float>(size);
            for (int i = 0; i < size; i++) {
                t = float(rand())/float((RAND_MAX)) * 1;
                seq_i->Set(i,i+t);
                seq_d->Set(i,size-i+t);
                seq_r->Set(i, float(rand())/float((RAND_MAX)) * size);
                seq_i2->Set(i,i+t);
                seq_d2->Set(i,size-i+t);
                seq_r2->Set(i, float(rand())/float((RAND_MAX)) * size);
            }
            clock_t start = clock();
            sortMerge(seq_i,0,size-1);
            clock_t end = clock();
            double seconds_i_m = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortShell(seq_i2,size);
            end = clock();
            double seconds_i_s = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortMerge(seq_d,0,size-1);
            end = clock();
            double seconds_d_m = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortShell(seq_d2,size);
            end = clock();
            double seconds_d_s = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortMerge(seq_r,0,size-1);
            end = clock();
            double seconds_r_m = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortShell(seq_r2,size);
            end = clock();
            double seconds_r_s = (double)(end - start) / CLOCKS_PER_SEC;

            show_table(seconds_i_m,seconds_i_s,seconds_d_m,seconds_d_s,seconds_r_m,seconds_r_s);
        }
        else if (function == 3)
        {
            int size;
            float re,im;
            complex t1,t2,t3;
            cout<<"Enter size - "<<endl;
            cin>>size;
            auto *seq_i = new ArraySequence<complex>(size);
            auto *seq_d = new ArraySequence<complex>(size);
            auto *seq_r = new ArraySequence<complex>(size);
            auto *seq_i2 = new ArraySequence<complex>(size);
            auto *seq_d2 = new ArraySequence<complex>(size);
            auto *seq_r2 = new ArraySequence<complex>(size);
            for (int i = 0; i < size; i++) {
                re = i + float(rand())/float((RAND_MAX)) * 1;
                im = float(rand())/float((RAND_MAX)) * 1;
                t1 = complex(re,im);
                t2 =  complex(size-re,im);
                t3 = complex(float(rand())/float((RAND_MAX)) * size,float(rand())/float((RAND_MAX)) * 1);
                seq_i->Set(i,t1);
                seq_d->Set(i,t2);
                seq_r->Set(i, t3);
                seq_i2->Set(i,t1);
                seq_d2->Set(i,t2);
                seq_r2->Set(i, t3);
            }
            clock_t start = clock();
            sortMerge(seq_i,0,size-1);
            clock_t end = clock();
            double seconds_i_m = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortShell(seq_i2,size);
            end = clock();
            double seconds_i_s = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortMerge(seq_d,0,size-1);
            end = clock();
            double seconds_d_m = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortShell(seq_d2,size);
            end = clock();
            double seconds_d_s = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortMerge(seq_r,0,size-1);
            end = clock();
            double seconds_r_m = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            sortShell(seq_r2,size);
            end = clock();
            double seconds_r_s = (double)(end - start) / CLOCKS_PER_SEC;

            show_table(seconds_i_m,seconds_i_s,seconds_d_m,seconds_d_s,seconds_r_m,seconds_r_s);
        }
    }
}


[[noreturn]] void MenuSortMerge()
{
    while(true) {
        int type = ChooseTypeInput();
        if (type == 0) {
            break;
        } else if (type == 1) {
            while (true) {
                int function = ChooseTypeSeq();
                if (function == 0) {
                    break;
                }
                if (function == 1) {


                    int t, n;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    auto *seq = new ArraySequence<int>(n);
                    for (int i = 0; i < n; i++) {
                        cout << "Enter a number - " << endl;
                        cin >> t;
                        seq->Set(i, t);
                    }
                    cout << "Initial sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i) << " ";
                    }
                    sortMerge(seq, 0, n - 1);

                    cout << "\n";

                    cout << "Final sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i) << " ";
                    }
                    cout << "\n";
                } else if (function == 2) {
                    int n;
                    float t;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    auto *seq = new ArraySequence<float>(n);
                    for (int i = 0; i < n; i++) {
                        cout << "Enter a number - " << endl;
                        cin >> t;
                        seq->Set(i, t);
                    }
                    cout << "Initial sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i) << " ";
                    }
                    sortMerge(seq, 0, n - 1);

                    cout << "\n";

                    cout << "Final sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i) << " ";
                    }
                    cout << "\n";
                } else if (function == 3) {
                    int n;
                    complex t;
                    float re, im;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    auto *seq = new ArraySequence<complex>(n);
                    for (int i = 0; i < n; i++) {
                        cout << "Enter a number - " << endl;
                        cin >> re >> im;
                        t = complex(re, im);
                        seq->Set(i, t);
                    }
                    cout << "Initial sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i).real() << "+" << seq->Get(i).imag() << "i ";
                    }
                    sortMerge(seq, 0, n - 1);

                    cout << "\n";

                    cout << "Final sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i).real() << "+" << seq->Get(i).imag() << "i ";
                    }
                    cout << "\n";
                }
            }
        }
        else if (type == 2) {
            while (true) {

                int function = ChooseTypeSeq();
                if (function == 0) {
                    break;
                }
                if (function == 1) {


                    int t,board, n;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    cout << "Enter board - " << endl;
                    cin >> board;
                    auto *seq = new ArraySequence<int>(n);
                    auto *seqf = new ArraySequence<int>(n);
                    for (int i = 0; i < n; i++) {
                        t = (1 + rand() % board);
                        seq->Set(i, t);
                        seqf->Set(i,t);
                    }
                    sortMerge(seq, 0, n - 1);
                    int mask=0;
                    for (int i=0;i<n-1;i++)
                    {
                        if (seq->Get(i)<seq->Get(i+1) && seq->Get(i)==seq->Get(i+1))
                        {
                            mask = 1;
                            break;
                        }
                    }
                    if (mask == 0)
                    {
                        cout<<"No mistakes :)"<<endl;
                    }
                    else{cout<<"Yes mistakes :("<<endl;}
                    if (n<100)
                    {
                        cout << "Initial sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seqf->Get(i) << " ";
                        }

                        cout << "\n";

                        cout << "Final sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seq->Get(i) << " ";}
                        cout << "\n";}
                    else{cout<<"size larger than 100"<<endl;}
                } else if (function == 2) {
                    int board, n;
                    float t;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    cout << "Enter board - " << endl;
                    cin >> board;
                    auto *seq = new ArraySequence<float>(n);
                    auto *seqf = new ArraySequence<float>(n);
                    for (int i = 0; i < n; i++) {
                        t = float(rand())/float((RAND_MAX)) * board;
                        seq->Set(i, t);
                        seqf->Set(i,t);
                    }
                    sortMerge(seq, 0, n - 1);
                    int mask=0;
                    for (int i=0;i<n-1;i++)
                    {
                        if (seq->Get(i)<seq->Get(i+1) && seq->Get(i)==seq->Get(i+1))
                        {
                            mask = 1;
                            break;
                        }
                    }
                    if (mask == 0)
                    {
                        cout<<"No mistakes :)"<<endl;
                    }
                    else{cout<<"Yes mistakes :("<<endl;}
                    if (n<100)
                    {
                        cout << "Initial sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seqf->Get(i) << " ";
                        }

                        cout << "\n";

                        cout << "Final sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seq->Get(i) << " ";}
                        cout << "\n";}
                    else{cout<<"size larger than 100"<<endl;}
                } else if (function == 3) {
                    int board, n;
                    complex t;
                    float re,im;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    cout << "Enter board - " << endl;
                    cin >> board;
                    auto *seq = new ArraySequence<complex>(n);
                    auto *seqf = new ArraySequence<complex>(n);
                    for (int i = 0; i < n; i++) {
                        re = float(rand())/float((RAND_MAX)) * board;
                        im = float(rand())/float((RAND_MAX)) * board;
                        t = complex(re,im);
                        seq->Set(i, t);
                        seqf->Set(i,t);
                    }
                    sortMerge(seq, 0, n - 1);
                    int mask=0;
                    for (int i=0;i<n-1;i++)
                    {
                        if (seq->Get(i)<seq->Get(i+1) && seq->Get(i)==seq->Get(i+1))
                        {
                            mask = 1;
                            break;
                        }
                    }
                    if (mask == 0)
                    {
                        cout<<"No mistakes :)"<<endl;
                    }
                    else{cout<<"Yes mistakes :("<<endl;}
                    if (n<100)
                    {
                        cout << "Initial sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seqf->Get(i).real() << " + "<<seqf->Get(i).imag()<<"i ";
                        }

                        cout << "\n";

                        cout << "Final sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seq->Get(i).real() << " + "<<seqf->Get(i).imag()<<"i ";}
                        cout << "\n";}
                    else{cout<<"size larger than 100"<<endl;}

            }
       }
    }
}}

[[noreturn]] void MenuSortShell()
{
    while(true) {
        int type = ChooseTypeInput();
        if (type == 0) {
            break;
        } else if (type == 1) {
            while (true) {
                int function = ChooseTypeSeq();
                if (function == 0) {
                    break;
                }
                if (function == 1) {


                    int t, n;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    auto *seq = new ArraySequence<int>(n);
                    for (int i = 0; i < n; i++) {
                        cout << "Enter a number - " << endl;
                        cin >> t;
                        seq->Set(i, t);
                    }
                    cout << "Initial sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i) << " ";
                    }
                    sortShell(seq, n);

                    cout << "\n";

                    cout << "Final sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i) << " ";
                    }
                    cout << "\n";
                } else if (function == 2) {
                    int n;
                    float t;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    auto *seq = new ArraySequence<float>(n);
                    for (int i = 0; i < n; i++) {
                        cout << "Enter a number - " << endl;
                        cin >> t;
                        seq->Set(i, t);
                    }
                    cout << "Initial sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i) << " ";
                    }
                    sortShell(seq, n );

                    cout << "\n";

                    cout << "Final sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i) << " ";
                    }
                    cout << "\n";
                } else if (function == 3) {
                    int n;
                    complex t;
                    float re, im;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    auto *seq = new ArraySequence<complex>(n);
                    for (int i = 0; i < n; i++) {
                        cout << "Enter a number - " << endl;
                        cin >> re >> im;
                        t = complex(re, im);
                        seq->Set(i, t);
                    }
                    cout << "Initial sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i).real() << "+" << seq->Get(i).imag() << "i ";
                    }
                    sortShell(seq, n);

                    cout << "\n";

                    cout << "Final sequence: ";
                    for (int i = 0; i < n; i++) {
                        cout << seq->Get(i).real() << "+" << seq->Get(i).imag() << "i ";
                    }
                    cout << "\n";
                }
            }
        }
        else if (type == 2) {
            while (true) {
                int function = ChooseTypeSeq();
                if (function == 0)
                {
                    break;
                }
                if (function == 1) {


                    int t,board, n;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    cout << "Enter board - " << endl;
                    cin >> board;
                    auto *seq = new ArraySequence<int>(n);
                    auto *seqf = new ArraySequence<int>(n);
                    for (int i = 0; i < n; i++) {
                        t = (1 + rand() % board);
                        seq->Set(i, t);
                        seqf->Set(i,t);
                    }
                    sortShell(seq,  n);
                    int mask=0;
                    for (int i=0;i<n-1;i++)
                    {
                        if (seq->Get(i)<seq->Get(i+1) && seq->Get(i)==seq->Get(i+1))
                        {
                            mask = 1;
                            break;
                        }
                    }
                    if (mask == 0)
                    {
                        cout<<"No mistakes :)"<<endl;
                    }
                    else{cout<<"Yes mistakes :("<<endl;}
                    if (n<100)
                    {
                        cout << "Initial sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seqf->Get(i) << " ";
                        }

                        cout << "\n";

                        cout << "Final sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seq->Get(i) << " ";}
                        cout << "\n";}
                    else{cout<<"size larger than 100"<<endl;}
                } else if (function == 2) {
                    int board, n;
                    float t;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    cout << "Enter board - " << endl;
                    cin >> board;
                    auto *seq = new ArraySequence<float>(n);
                    auto *seqf = new ArraySequence<float>(n);
                    for (int i = 0; i < n; i++) {
                        t = float(rand())/float((RAND_MAX)) * board;
                        seq->Set(i, t);
                        seqf->Set(i,t);
                    }
                    sortShell(seq, n );
                    int mask=0;
                    for (int i=0;i<n-1;i++)
                    {
                        if (seq->Get(i)<seq->Get(i+1) && seq->Get(i)==seq->Get(i+1))
                        {
                            mask = 1;
                            break;
                        }
                    }
                    if (mask == 0)
                    {
                        cout<<"No mistakes :)"<<endl;
                    }
                    else{cout<<"Yes mistakes :("<<endl;}
                    if (n<100)
                    {
                        cout << "Initial sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seqf->Get(i) << " ";
                        }

                        cout << "\n";

                        cout << "Final sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seq->Get(i) << " ";}
                        cout << "\n";}
                    else{cout<<"size larger than 100"<<endl;}
                } else if (function == 3) {
                    int board, n;
                    complex t;
                    float re,im;
                    cout << "Enter size - " << endl;
                    cin >> n;
                    cout << "Enter board - " << endl;
                    cin >> board;
                    auto *seq = new ArraySequence<complex>(n);
                    auto *seqf = new ArraySequence<complex>(n);
                    for (int i = 0; i < n; i++) {
                        re = float(rand())/float((RAND_MAX)) * board;
                        im = float(rand())/float((RAND_MAX)) * board;
                        t = complex(re,im);
                        seq->Set(i, t);
                        seqf->Set(i,t);
                    }
                    sortShell(seq,n);
                    int mask=0;
                    for (int i=0;i<n-1;i++)
                    {
                        if (seq->Get(i)<seq->Get(i+1) && seq->Get(i)==seq->Get(i+1))
                        {
                            mask = 1;
                            break;
                        }
                    }
                    if (mask == 0)
                    {
                        cout<<"No mistakes :)"<<endl;
                    }
                    else{cout<<"Yes mistakes :("<<endl;}
                    if (n<100)
                    {
                        cout << "Initial sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seqf->Get(i).real() << " + "<<seqf->Get(i).imag()<<"i ";
                        }

                        cout << "\n";

                        cout << "Final sequence: ";
                        for (int i = 0; i < n; i++) {
                            cout << seq->Get(i).real() << " + "<<seqf->Get(i).imag()<<"i ";}
                        cout << "\n";}
                    else{cout<<"size larger than 100"<<endl;}

                }
            }
    }
}}



int menu()
{
        while(true){
            int classType;
            cout << " Merge Sort - 1 \n Shell Sort - 2 \n Сomparison of algorithms - 3 \n Exit ->" << endl;
            cin >> classType;
            cout << endl;
            if (classType != 0 & classType != 1 & classType != 2){
                cout << "The number is incorrect. Please, enter the correct number" << endl;
            }
            if(classType == 1){
                MenuSortMerge();
            }
            else if (classType == 2){
                MenuSortShell();
            }
            else if (classType == 3){
                MenuComprasion();
            }
            else if (classType == 0){
                break;
            }
        }
        return 0;}



