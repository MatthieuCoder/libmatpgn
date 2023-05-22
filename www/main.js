/**
 * 
 * @param {Event} e 
 */
function on_file_select(e) {
    console.log(e);
    document.querySelector('#content_file').textContent = e.value.replace(/.*[\/\\]/, '');
}