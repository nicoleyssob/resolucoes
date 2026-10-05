#include <stdio.h>
 
int main() {
 
    float porc=0,pors=0,porr=0;
    int n=0,qtd=0,c=0,s=0,r=0,total=0;
    char tipo;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&qtd);
        scanf(" %c",&tipo);
        switch(tipo){
            case 'C':
            c+=qtd;
            break;
            case 'R':
            r+=qtd;
            break;
            case 'S':
            s+=qtd;
            break;
            default:
            break;
        }
    }
    total=s+c+r;
    pors=(s*100.0)/total;
    porc=(c*100.0)/total;
    porr=(r*100.0)/total;
    printf("Total: %d cobaias\n",total);
    printf("Total de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\n",c,r,s);
    printf("Percentual de coelhos: %.2f %%\nPercentual de ratos: %.2f %%\nPercentual de sapos: %.2f %%\n",porc,porr,pors);
 
    return 0;
}