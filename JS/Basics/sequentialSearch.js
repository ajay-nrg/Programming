a = [10,2,3,6,19,32,9,22,3,9,7];
k = process.argv[2]
let res = search(a,k);
if(res!=-1)
    console.log(`element found at location ${res}`);
else
    console.log('Element not found');

function search(a,k){
    for(let i=0;i<a.length;i++){
        if(a[i]==k)
            return i;
    }    
    return -1;
}