#include "menu.h"
#include "Function.h"
#include "cmath"

using namespace std;

//�������������
void printArray(int M[],int numOfM){
    cout<<"�����Ϊ��";
    for(int i = 0;i < numOfM;i++){
        cout<<M[i]<<" ";
    }
    cout<<endl;
}

//ֱ�Ӳ������򣨽���
int* Straight_Insertion_Sort(int M[],int numOfM){
    //N��������������������
    int N[numOfM],numOfN = 1;
    N[0] = M[0];
    for(int i = 1;i < numOfM;i++){
        int indexOfMin = 0;
        for(int j = 0;j < numOfN;j++){
            if(M[i] >= N[j]){
                //����
                for(int x = numOfN;x > j;x--){
                    N[x] = N[x - 1];
                }
                N[j] = M[i];
                numOfN++;
                indexOfMin++;
                break;
            }
        }
        if(indexOfMin == 0){
            N[numOfN] = M[i];
            numOfN++;
        }
    }

    for(int i = 0;i < numOfM;i++){
        M[i] = N[i];
    }

    return M;
}

//ѡ����������
int* Select_Sort(int M[],int numOfM){
    /**
     * ÿ�γ�ȡ��С��������ʼ������λ��
     * �����ʼ��������
     * ѭ��������������
    */
    for(int i = 0;i < numOfM;i++){
        int minOfM = INT_MAX,minIndex;
        //�ҳ���Сֵ�Լ�������
        for(int j = i;j < numOfM;j++){
            if(M[j] < minOfM){
                minOfM = M[j];
                minIndex = j;
            }
        }
        //��Сֵ����ʼ������λ��
        if(minOfM < M[i]){
            int index;
            index = M[i];
            M[i] = minOfM;
            M[minIndex] = index;
        }
    }
    return M;
}

//�鲢����(����)
int* Merge_Sort_up(int M[],int numOfM){
    /**
     * ����
     * �жϣ��ڲ��Ƚϳ�������Խ����ֹͣ��������������Ԫ��ֱ�ӵ��Ӽ���
     * numOfG����ÿ���и�Ĵ�С
     * ���ѭ�������и��С���ڲ�ѭ����������������и�
    */
    for(int numOfG = 1;numOfG < numOfM;numOfG *= 2){
        //N�����¼��ˢ��ǰ�����飬��ÿ���ڲ�ѭ����������ˢ��
        int N[numOfM];
        for(int i = 0;i < numOfM;i++){
            N[i] = M[i];
        }
        //�����ڲ�������µ�������
        int index = 0;
        for(int start1 = 0;start1 < numOfM;start1 += numOfG){
            int end1 = start1 + numOfG - 1,end2 = start1 + 2 * numOfG - 1,start2 = end1 + 1;
            //��Ϊǰ���鲻��������
            if(start2 >= numOfM){
                break;
            }
            //�жϣ�ֻҪstart1����start2��һ����Խ����ֹͣѭ����ת��ֱ�ӵ���
            while(index <= end2){
                //�ж��Ƿ��ж�
                if(start1 > end1){
                    while(start2 <= end2){
                        M[index] = N[start2];
                        start2++;
                        index++;
                    }
                    break;
                }
                if(start2 > end2 || start2 >= numOfM){
                    while(start1 <= end1){
                        M[index] = N[start1];
                        start1++;
                        index++;
                    }
                    break;
                }
                //�鲢�����ȶ�����
                if(N[start1] <= N[start2]){
                    M[index] = N[start1];
                    start1++;
                    index++;
                }else{
                    M[index] = N[start2];
                    start2++;
                    index++;
                }
            }
        }
    }

    return M;
}

//�鲢����(����)
int* Merge_Sort_down(int M[],int numOfM){
    /**
     * ����
     * �жϣ��ڲ��Ƚϳ�������Խ����ֹͣ��������������Ԫ��ֱ�ӵ��Ӽ���
     * numOfG����ÿ���и�Ĵ�С
     * ���ѭ�������и��С���ڲ�ѭ����������������и�
    */
    for(int numOfG = 1;numOfG < numOfM;numOfG *= 2){
        //N�����¼��ˢ��ǰ�����飬��ÿ���ڲ�ѭ����������ˢ��
        int N[numOfM];
        for(int i = 0;i < numOfM;i++){
            N[i] = M[i];
        }
        //�����ڲ�������µ�������
        int index = 0;
        for(int start1 = 0;start1 < numOfM;start1 += numOfG){
            int end1 = start1 + numOfG - 1,end2 = start1 + 2 * numOfG - 1,start2 = end1 + 1;
            //��Ϊǰ���鲻��������
            if(start2 >= numOfM){
                break;
            }
            //�жϣ�ֻҪstart1����start2��һ����Խ����ֹͣѭ����ת��ֱ�ӵ���
            while(index <= end2){
                //�ж��Ƿ��ж�
                if(start1 > end1){
                    while(start2 <= end2){
                        M[index] = N[start2];
                        start2++;
                        index++;
                    }
                    break;
                }
                if(start2 > end2 || start2 >= numOfM){
                    while(start1 <= end1){
                        M[index] = N[start1];
                        start1++;
                        index++;
                    }
                    break;
                }
                /**
                 * �鲢�����ȶ�����
                 * ����Ҳ�������������
                */
                if(N[start1] >= N[start2]){
                    M[index] = N[start1];
                    start1++;
                    index++;
                }else{
                    M[index] = N[start2];
                    start2++;
                    index++;
                }
            }
        }
    }

    return M;
}

//����������
int* Heap_Sort_up(int M[],int numOfM){
    /**
     * �����������ķ�������������Ϊ��ַ����Ա�������+1�Լ�����/2
     * �����ռ临�Ӷ�ΪO(1)
     * ͨ�����������������Ѿ�������Ԫ�ز��ٲ�������
     * �������ε�
    */

    //δ����Ԫ��ȫ���������У�numOfTָ��δ����Ԫ�ظ�����indexOfTΪδ����Ԫ�ص�βָ��
    int numOfT = numOfM,indexOfT;
    //Ԫ������Ϊ����ʱ��Ϊ��ȫ����������ʱ��numOfM - 1��ָ����ĩβԪ��
    //Ԫ������Ϊż��ʱ��Ϊ����ȫ��������numOfM - 1ָ������

    //ÿ��ˢ�º󶼻����Ϊ�󶥶�
    for(;numOfT > 0;numOfT--){
        //���ж�����Ϊ��indexOfT��Զָ����ĩβ������
        if(numOfT % 2 == 1){
            //���������
            indexOfT = numOfT - 2;
        }else if(numOfT % 2 == 0){
            //ż�������
            indexOfT = numOfT - 1;
        }

        //depth������������
        int depth = 3;
        for(int time = 0;time < depth - 1;time++){
        //���´󶥶ѣ�i������������
            for(int i = indexOfT;i > 0;i -= 2){
                //�Ƚ��������Ĵ�С�������󶥶�
                //���Һ����Ѿ�����������򲻱Ƚ��Һ���
                if(i + 1 != numOfT){
                    if(M[i] >= M[i + 1] && M[i] >= M[i / 2]){
                        //IV���м����
                        int IV = M[i];
                        M[i] = M[i / 2];
                        M[i / 2] = IV;
                    }else if(M[i + 1] >= M[i] && M[i + 1] >= M[i / 2]){
                        int IV = M[i + 1];
                        M[i + 1] = M[i / 2];
                        M[i / 2] = IV;
                    }
                }else{
                    if(M[i] >= M[i / 2]){
                        int IV = M[i];
                        M[i] = M[i / 2];
                        M[i / 2] = IV;
                    }
                }
            }
        }

        //����ͻĩβ����λ��
        int IV = M[numOfT - 1];
        M[numOfT - 1] = M[0];
        M[0] = IV;
    }

    return M;
}

//�����򣨽���
int* Heap_Sort_down(int M[],int numOfM){
    int numOfT = numOfM,indexOfT;
    for(;numOfT > 0;numOfT--){
        if(numOfT % 2 == 1){
            indexOfT = numOfT - 2;
        }else if(numOfT % 2 == 0){
            indexOfT = numOfT - 1;
        }

        int depth = 3;
        for(int time = 0;time < depth - 1;time++){
            for(int i = indexOfT;i > 0;i -= 2){
                if(i + 1 != numOfT){
                    if(M[i] <= M[i + 1] && M[i] <= M[i / 2]){
                        int IV = M[i];
                        M[i] = M[i / 2];
                        M[i / 2] = IV;
                    }else if(M[i + 1] <= M[i] && M[i + 1] <= M[i / 2]){
                        int IV = M[i + 1];
                        M[i + 1] = M[i / 2];
                        M[i / 2] = IV;
                    }
                }else{
                    if(M[i] <= M[i / 2]){
                        int IV = M[i];
                        M[i] = M[i / 2];
                        M[i / 2] = IV;
                    }
                }
            }
        }

        int IV = M[numOfT - 1];
        M[numOfT - 1] = M[0];
        M[0] = IV;
    }

    return M;
}

//˳�����
int Sequential_Search(int M[],int numOfM,int index){
    for(int i = 0;i < numOfM;i++){
        if(index == M[i]){
            return i;
        }
    }
    return -1;
}

//�۰����
int Half_interval_Search(int M[],int numOfM,int index,bool up_or_down){
    int low = 0,high = numOfM - 1,mid = (low + high) / 2;

    //����Ϊ����
    if(up_or_down){
        while(high >= low){
            mid = (low + high) / 2;
            if(M[mid] == index){
                return mid;
            }else{
                if(M[mid] > index){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
        }
    }else{
        while(high >= low){
            mid = (low + high) / 2;
            if(M[mid] == index){
                return mid;
            }else{
                if(M[mid] < index){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
        }
    }

    return -1;
}

//�鼮����
void book_sort(book somebook[],int numOfbook){
    for(int i = 0;i < numOfbook;i++){
        int minOfM = INT_MAX,minIndex;
        //�ҳ���Сֵ�Լ�������
        for(int j = i;j < numOfbook;j++){
            if(somebook[j].price < minOfM){
                minOfM = somebook[j].price;
                minIndex = j;
            }
        }
        //��Сֵ����ʼ������λ��
        if(minOfM < somebook[i].price){
            book index;
            index.price = somebook[i].price;
            index.name = somebook[i].name;
            somebook[i].price = minOfM;
            somebook[i].name = somebook[minIndex].name;
            somebook[minIndex].price = index.price;
            somebook[minIndex].name = index.name;
        }
    }


    cout<<"�����Ϊ��"<<endl;
    for(int i = 0;i < numOfbook;i++){
        cout<<somebook[i].name<<"---";
        cout<<somebook[i].price<<endl;
    }
}
