msString ms = msSetString (" Hello ");
msString ms2 = msSetString (" World !");
msString mscopy = NULL ;

printf (" String |% s | is % ld characters long (% p ).\ n " ,
msGetString ( ms ) , msLength ( ms ) , ms );
msCopy (& mscopy , ms );
printf (" Copied string |% s | is % ld characters long (% p ).\ n " ,
msGetString ( mscopy ) , msLength ( mscopy ) , mscopy );
printf (" Compare ms with mscopy : % d \ n " , msCompare ( ms , mscopy ));
printf (" Compare ms with ms2 : % d \ n " , msCompare ( ms , ms2 ));
printf (" Compare ms with Hello : % d \ n " , msCompareString ( ms ," Hello "));
printf (" Compare ms with HelloX : % d \ n " , msCompareString ( ms ," HelloX "));
printf (" Compare ms with Hella : % d \ n " , msCompareString ( ms ," Hella "));
msConcatenate (& mscopy , ms2 );
printf (" Concatenated string |% s| is %ld characters long (%p).\ n " ,msGetString (mscopy), msLength(mscopy), mscopy);

