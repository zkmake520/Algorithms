public class URLShortener{
	/*
	Solution:We need a bijective function, from long url to short url and shor url to long url.
	And this mapping should be stored 
	Simple Solution: Use a hash function to convert long string to short string. In hashing, there may be
	collisions, so can't access long url back by using short url. It just looks like access back from value to key,
	which means given a value can u get the key back? Apperantly not!
	A better solution: we can use a unqiue id for each long url ,and convert this unique id to short url. Then there will be 
	unique one to one mapping!


	Thus the problem becomes mapping an Integer id to a short string
	Bellow is one important observation about possible characters in URL
	A URL character can be one of the following
	1) A lower case alphabet [‘a’ to ‘z’], total 26 characters
	2) An upper case alphabet [‘A’ to ‘Z’], total 26 characters
	3) A digit [‘0′ to ‘9’], total 10 characters
	There are total 26 + 26 + 10 = 62 possible characters.

	And in database, we only need to store the mapping from the id to long url.Acutally, the id can be obtained by using the 
	automic increment integer id in database
	
	A little more about url shortener in distributed and concurrent environment.
	We can see that this method is very easy to scale. What's more we even don't need to consider about mutual exclusion.
	Suppose we want to extend to use 10 servers to do url shorten. for each server we just need to increse the id by 10. For example, 
	server 1 has a base id 1, the next id will be 11 and then 21.. and so on.
	*/
	static int id = 10000;
	public static String urlShorten(){
		String mappings = new String("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
		String shortUrl = "";
		id++;
		while(id > 0){
			shortUrl += mappings.charAt(id%62);
			id = id / 62; 	
		}
		return shortUrl;
	} 
	public static int getId(String shortUrl){
		int id = 0;
		for(int i = shortUrl.length()-1; i >= 0; i--){
			char c = shortUrl.charAt(i);
			if(c >= 'a' && c <='z'){
				id = id*62 + c-'a';
			}
			if(c >= 'A' && c <= 'Z'){
				id = id*62 + c-'A' + 26;
			}
			if( c>='0' && c <= '9'){
				id = id*62 + c -'0' +52;
			}
		}	
		return id;
	}
	public static void main(String []args){
		String shortUrl = URLShortener.urlShorten();
		System.out.println(shortUrl);
		System.out.println(URLShortener.getId(shortUrl));
	}
}