#!/usr/bin/env python
import mwclient
from mwclient import Site
# tutorial: https://www.snpedia.com/index.php/Bulk#Python

import asyncio

async def get_the_snpedia_text(snp_id):
    #site.pages['Rs1002765'].text()
    site = mwclient.Site(('https', 'bots.snpedia.com'), path='/')
    txt = site.pages[snp_id].text()
    #print(txt)
    wfile = open('./SNPedia/{}.mw'.format(snp_id),'w')
    wfile.write(txt)
    wfile.close()

#agent = 'MySNPBot. Run by User:markliou markliou@ms51.url.com.tw Using mwclient/' + mwclient.__ver__
# tokens and secrets are only necessary if your bot will write into SNPedia.
# get your own tokens at http://bots.snpedia.com/index.php/Special:OAuthConsumerRegistration
site = mwclient.Site(('https', 'bots.snpedia.com'), path='/'
                    #clients_useragent=agent,
                    #consumer_token='',
                    #consumer_secret='',
                    #access_token='',
                    #access_secret=''
                    )
                    
#for i, page in enumerate(site.Categories['Is_a_snp']):
# catagories: https://www.snpedia.com/index.php/Special:Categories
# for i in site.Categories['In_dbSNP']:
    # print(i.name) 

asyn_loop = asyncio.get_event_loop()
tasks = [ get_the_snpedia_text(i.name) for i in site.Categories['In_dbSNP'] ]
#tasks = [ get_the_snpedia_text(i) for i in ['Rs1002765','Rs1003199','Rs10048158'] ]  
asyn_loop.run_until_complete(asyncio.wait(tasks))
asyn_loop.close()  
                    