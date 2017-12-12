#include <pcap.h>  
#include <stdio.h>  


void findAllDevs()
{
    pcap_if_t *net_card_info_list = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    int i = 0;
    pcap_if_t *p_net_card_info = NULL;

    //¿¿¿¿¿¿¿alldevs¿¿¿¿ 
    if (pcap_findalldevs(&net_card_info_list, errbuf) == -1)
    {
        fprintf(stderr,"Error in pcap_findalldevs: %s\n", errbuf);
        goto end;
    }

    for(p_net_card_info = net_card_info_list; p_net_card_info; p_net_card_info = p_net_card_info->next)
    {
        printf("%d. %s", ++i, p_net_card_info->name);
        if (p_net_card_info->description)
        {
            printf(" (%s)\n", p_net_card_info->description);
        }
        else
        {
            printf(" (No description available)\n");
        }
    }

    if(0 == i)
    {
        printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
        goto end;
    }


end:
    return;
}

void pcap_lookupdev_test(void)
{
    char errBuf[PCAP_ERRBUF_SIZE], * device;  

    device = pcap_lookupdev(errBuf);  

    if(device)  
    {  
        printf("success: device: %s\n", device);  
    }  
    else  
    {  
        printf("error: %s\n", errBuf);  
    }
}

int main()
{
	findAllDevs();

    return 0;  
}  

