 #include<malloc.h>
 #include<pthread.h>
 #include<stdio.h>

void *allocate_buffer(size_t size)
 {
	printf("Resource Allocated\n");
	return malloc(size);
 }

 void deallocate_buffer(void * buffer)
 {
	free(buffer);
	printf("\nResources Freed\n");
 }

 void *do_some_work(void *p)
 {
	void *temp_buffer = allocate_buffer(1024);
	int i;

 	pthread_cleanup_push(deallocate_buffer, temp_buffer);
	for(i = 0; i < 100000; i++)
		fputc('c', stderr);	
	pthread_cleanup_pop(0);
//	deallocate_buffer(temp_buffer);	
}
 int main()
 {
	pthread_t thread_id;
	
	pthread_create(&thread_id, NULL, &do_some_work, NULL);
//	sleep(2);
	pthread_cancel(thread_id);
	pthread_join(thread_id, NULL);
	
	return 0;
 }
