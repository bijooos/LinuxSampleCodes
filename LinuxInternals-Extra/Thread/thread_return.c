 #include<pthread.h>
 #include<stdio.h>

 struct parms
 {
	int a;
	int b;
 };

 void *add(void *a)
 {
	struct parms *d = (struct parms *)a;
	int c;
	c  = (d->a + d->b);
	return ((void *)c);
 }

 int main()
 {
	pthread_t thread_id;
	struct parms p;
	int c;
	printf("\nEnter a and b\n");
	scanf("%d %d", &p.a, &p.b);
	
	pthread_create(&thread_id, NULL, &add, &p);
	pthread_join(thread_id, (void *)&c);
	printf("\nThe Value after Execution is %d\n", c);
	return 0;
 }
