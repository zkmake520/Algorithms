import org.junit.Test;
import static org.junit.Assert.assertEquals;
public class UnitTest {
  	@Test
	public void test(){
	
		ArrayToSet<Integer> excep = new ArrayToSet<Integer>(-1);
		ArrayToSet<Integer> empty = new ArrayToSet<Integer>(5);
		ArrayToSet<Integer> limited = new ArrayToSet<Integer>(0);
		Integer[] a = new Integer[]{2,3,4};
		ArrayToSet<Integer> contain = new ArrayToSet<Integer>(3,a);
		ArrayToSet<Integer> nullObject = new ArrayToSet<Integer>(null);
		boolean rst = false;
		//test empty
		assertEquals(true,empty.isEmpty()); 

		//test true contain
		assertEquals(true,contain.contains(2));   
		//test size
		assertEquals(3,contain.size());   

		//test false contain 
		assertEquals(false,empty.contains(3));  
		//test add  return
		rst = empty.add(3);
		assertEquals(true,rst);
		//test add
		assertEquals(true,empty.contains(3));  
		//test add size
		assertEquals(1,empty.size());  

		//test duplicate  return and size
		assertEquals(false,empty.add(3)); 
		assertEquals(1,empty.size()); 

		//Test remove and contains and size
		rst = empty.remove(3);
		assertEquals(true,rst); 
		assertEquals(0,empty.size());
		assertEquals(false,empty.contains(3));

		//Test 0 capacity
		rst = limited.isEmpty();
		assertEquals(true,rst);
		rst = limited.add(3);
		assertEquals(false,rst);
		assertEquals(false,limited.contains(3));





		//Test NULL
		rst =empty.add(null);
		assertEquals(rst,true);
		assertEquals(true,empty.contains(null));
		rst = empty.remove(3);
		assertEquals(false,rst);
		rst = empty.remove(null);
		assertEquals(true,rst);
		assertEquals(0,empty.size());
		//Test if pass NULL to constructor
		//
		//Test null array
		assertEquals(false, nullObject.add(3));
		assertEquals(false, nullObject.remove(3));
		assertEquals(false, nullObject.add(3));

		//

	}

}