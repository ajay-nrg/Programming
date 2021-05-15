let n=10;
let i,j;
let a = new Array(n+1);
let l = new Array(n+1);
for(i=0;i<=n;i++){
    a[i] = i;
}
for(i=2;i<=Math.sqrt(Math.floor(n));i++){
    if(a[i]!=0){
        j=i*i;
        while(j<=n){
            a[j] = 0;
            j+=i;
        }
    }
}
j=0;
for(i=2;i<=n;i++){
    if(a[i]!=0){
        l[j] = a[i];
        j++;
    }
}

//Print Result 
for(i=0;i<n;i++){
    console.log(l[i]);
}
