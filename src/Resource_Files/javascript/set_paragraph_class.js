var s = window.getSelection();
var r = s.getRangeAt(0);
var c = r.cloneContents();
var head = r.startContainer.parentElement;
var tail = r.endContainer.parentElement;
if (head == tail && (head.tagName == 'P' || head.tagName == 'p')){
	head.setAttribute('class', 'PPP');
}
else while (head != tail.nextElementSibling && head != null){
	if (head.tagName == 'P' || head.tagName == 'p'){
		head.setAttribute('class', 'PPP');
	}
	head=head.nextElementSibling;
}

var s = window.getSelection();
var r = s.getRangeAt(0);
var c = r.cloneContents();
var head = r.startContainer.parentElement;
var tail = r.endContainer.parentElement;
var div = document.createElement('div');
var cb = r.cloneContents();
div.append(c);
document.body.innerHTML = document.body.innerHTML.replace(cb.textContent, div.outerHTML);


while (head != tail.nextElementSibling && head != null){
	if (head.tagName == 'P' || head.tagName == 'p'){
		div.appendChild(head);
	}
	head=head.nextElementSibling;
}

while (oldParent.childNodes.length) { newParent.appendChild(oldParent.firstChild); }

function surroundSelection(element) {
    if (window.getSelection) {
        var sel = window.getSelection();
        if (sel.rangeCount) {
            var range = sel.getRangeAt(0).cloneRange();
            range.surroundContents(element);
            sel.removeAllRanges();
            sel.addRange(range);
        }
    }
}

(function surroundSelection() {
    var span = document.createElement('span');
    span.setAttribute('class', 'OOO');
    if (window.getSelection) {
        var sel = window.getSelection();
        if (sel.rangeCount) {
            var range = sel.getRangeAt(0).cloneRange();
            range.surroundContents(span);
            sel.removeAllRanges();
            sel.addRange(range);
        }
    }
})()

var s = window.getSelection();
var r = s.getRangeAt(0);
var head = r.startContainer.parentElement;
var tail = r.endContainer.parentElement;
var div = document.createElement('div');
div.setAttribute('class', 'YYY');
while (head != null && tail != null && head != tail){
	if (head.tagName == 'P' || head.tagName == 'p'){
		var temp = head;
		head=head.nextElementSibling;
		temp.parentNode.insertBefore(div, temp);
		div.appendChild(temp);
	}
}
if(head==tail){
	head.parentNode.insertBefore(div, head);
	div.appendChild(head);	
}
	