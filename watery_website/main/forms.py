from django import forms


class CreateNewList(forms.Form):
    name = forms.CharField(label="Name", max_length=200)
    com = forms.CharField(label="comment", max_length=1000)
    check = forms.BooleanField()
