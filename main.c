#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>


typedef struct {
    char nama[25];
    char email[25];
    int usia;
    int id;
    char kontak [25];
    char jabatan [25];
    char alamat [25];
}karyawan;
karyawan dk;
int cariid;

int pilihan;
int menuupdate;
int lastid;

FILE *datakarywan;
FILE *sementara;

int main(void) {
    while (1){
        system("color 71");
        Beep(1000,300);
        printf("\a");
        fflush(stdout);
        system("cls");

        printf("\t\t\t\t\t\tSelamat Datang di master karyawan ");
        printf("\t\t\t\t\t\t========================== ");
        printf("\n1.Tambah Data ");
        printf("\n2.Lihat Data ");
        printf("\n3.Update Data");
        printf("\n4.Hapus Data ");
        printf("\n5.Keluar");
        printf("\nmasukan pilihan (1-5) : ");
        scanf("%d",&pilihan);

        Beep(2000,300);
        printf("\a");
        fflush(stdout);
        system("cls");

        if(pilihan == 1) {
            datakarywan = fopen("datakarywan.dat", "ab");
                // printf("masukan Id karyawan :");
                // scanf("%d",&dk.id);

                lastid++;
                dk.id=lastid;

                printf("Masukan Nama Karyawan :");
                scanf(" %[^\n]%*c",dk.nama);

                printf("\nMasukan Jabatan 1 - 5 ");
                printf("\n1.Manager");
                printf("\n2.Customer Services");
                printf("\n3.Purchasing Staff");
                printf("\n4.Mekanik ");
                printf("\n5.Mekanik Checking");

                printf("\nmasukan Pilihan :");
                scanf(" %[^\n]%*c",dk.jabatan);

                printf("\nMasukan Usia anda :");
                scanf("%d",&dk.usia);

                printf("\nMasukan kontak Anda :");
                scanf(" %[^\n]%*c",dk.kontak);

                printf("\nMasukan Email Anda :");
                scanf(" %[^\n]%*c",dk.email);

                printf("\nMasukan Alamat Anda :");
                scanf(" %[^\n]%*c",dk.alamat);

                fwrite(&dk,sizeof(dk),1,datakarywan);
                fclose(datakarywan);

                Beep(100000,300);
                printf("\a");
                fflush(stdout);
            }


        else if (pilihan ==2 ) {
            datakarywan=fopen("datakarywan.dat","rb");
            printf("#################DATA KARYAWAN##################");
            while(fread(&dk,sizeof(dk),1,datakarywan)) {
                printf("\n\nId :KR 0%d",dk.id);
                printf("\nNama :%s",dk.nama);
                printf("\nUsia :%d",dk.usia);
                printf("\nJabatan :%s",dk.jabatan);
                printf("\nKontak :%s",dk.kontak);
                printf("\nEmail :%s",dk.email);
                printf("\nAlamat :%s",dk.alamat);
                //update id
                if(dk.id>lastid) {
                    lastid=dk.id;
                }
            }
            fclose(datakarywan);
        }

        else if (pilihan ==3) {
            printf("\nMasukan pilihan Update ");
            printf("\n1.Nama Karyawan");
            printf("\n2.Usia karyawan");
            printf("\n3.Kontak karyawan");
            printf("\n4.Email Karyawan");
            printf("\nMasukan Pilihan anda :");
            scanf("%d",&menuupdate);

            printf("masukan id karyawan yang ingin diupdate :KR 0");
            scanf("%d",&cariid);


                if (menuupdate==1) {
                        datakarywan=fopen("datakarywan.dat","rb");
                        sementara=fopen("sementara.dat","wb");

                        while (fread(&dk,sizeof(dk),1,datakarywan)) {
                              if(cariid == dk.id) {
                            printf("Masukan Nama Karyawan Yang Baru :");
                            scanf(" %[^\n]%*c",dk.nama);
                        }
                            fwrite(&dk,sizeof(dk),1,sementara);
                        }
                    fclose(sementara);
                    fclose(datakarywan);
                }

                else if (menuupdate==2) {
                        datakarywan=fopen("datakarywan.dat","rb");
                        sementara=fopen("sementara.dat","wb");
                        while (fread(&dk,sizeof(dk),1,datakarywan)) {
                            if(cariid == dk.id) {
                            printf("Masukan Usia Karyawan  :");
                            scanf("%d",&dk.usia);
                        }
                            fwrite(&dk,sizeof(dk),1,sementara);
                        }
                    fclose(sementara);
                    fclose(datakarywan);
                }

                else if (menuupdate ==3 ) {
                        datakarywan=fopen("datakarywan.dat","rb");
                        sementara=fopen("sementara.dat","wb");
                        while (fread(&dk,sizeof(dk),1,datakarywan)) {
                            if(cariid == dk.id) {
                                printf("Masukan Kontak Karyawan  :");
                                scanf(" %[^\n]%*c",dk.kontak);
                            }
                            fwrite(&dk,sizeof(dk),1,sementara);
                        }
                    fclose(sementara);
                    fclose(datakarywan);
                }

                else if (menuupdate ==4) {

                        datakarywan=fopen("datakarywan.dat","rb");
                        sementara=fopen("sementara.dat","wb");
                        while (fread(&dk,sizeof(dk),1,datakarywan)) {
                            if(cariid == dk.id) {
                            printf("Masukan email Karyawan  :");
                            scanf(" %[^\n]%*c",dk.email);
                        }
                            fwrite(&dk,sizeof(dk),1,sementara);
                    }
                    fclose(sementara);
                    fclose(datakarywan);
                }
            sementara=fopen("sementara.dat","rb");
            datakarywan=fopen("datakarywan.dat","wb");
            while (fread(&dk,sizeof(dk),1,sementara)) {
                fwrite(&dk,sizeof(dk),1,datakarywan);
            }
            fclose(datakarywan);
            fclose(sementara);
        }

        else if(pilihan ==4) {
            datakarywan=fopen("datakarywan.dat","rb");
            sementara=fopen("sementara.dat","wb");

            printf("Masukan Id karyawan Yang ingin dihapus :0");
            scanf("%d",&cariid);


            while (fread(&dk,sizeof(dk),1,datakarywan)) {
                if(dk.id != cariid) {
                    fwrite(&dk,sizeof(dk),1,sementara);
                }
            }
            fclose(sementara);
            fclose(datakarywan);

            //penulisan kembali
            sementara=fopen("sementara.dat","rb");
            datakarywan=fopen("datakarywan.dat","wb");

            while (fread(&dk,sizeof(dk),1,sementara)) {
                fwrite(&dk,sizeof(dk),1,datakarywan);
            }
            fclose(datakarywan);
            fclose(sementara);

            //update id
            datakarywan=fopen("datakarywan.dat","rb");
            lastid=0;
            while (fread(&dk,sizeof(dk),1,datakarywan)){
            if(dk.id >lastid)
            {
                lastid=dk.id;
            } }
            fclose(datakarywan);
        }
        else if(pilihan == 5) {
            exit(0);
        }
        getch();
    }
}

