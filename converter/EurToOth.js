
document.getElementById("numInput").addEventListener('input', function(e){
    let euro = e.target.value;
    document.getElementById("dollers").innerHTML = euro * 1.22 + "$";
    document.getElementById("pound").innerHTML = euro * 0.89 + "£";
});