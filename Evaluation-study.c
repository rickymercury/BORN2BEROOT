1) O que é uma Máquina Virtual (VM)?

Resposta: A VM é um software que simula o funcionamento de um computador físico de forma segura e controlada, 
          que permite executar sistemas operativos e aplicativos, num ambiente virtual isolado, como se fosse 
		  um computador físico, simulando recursos reais como a CPU, a memória, o armazenamento, etc, mas que,
		  na realidade, está tudo a ser executado dentro de um hardware de outro sistema físico (o host).

		  > é uma simulação baseada em software de um sistema físico do computador.
		  > uma VM é um ambiente isolado, separado do seu sistema principal. Nela, podemos executar diferentes
		    sistemas operacionais, softwares, aplicações e testes sem afetar o computador principal.

NOtas:

=> Quando criamos a VM no VirtualBox e instalamos o Debian nela, estamos a criar um computador virtual dentro do 
   nosso computador real. Dentro desta VM, criamos utilizadores, configuramos permissões, e fazemos a gestão do 
   sistema, tudo como se estivessemos num servidor físico real, mas com a vantagem de poder recomeçar facilmente 
   se algo correr mal.

=> As VMs oferecem flexibilidade, permitindo a execução de vários sistemas operacionais simultaneamente num único 
   computador físico, o que facilita o desenvolvimento e a execução de aplicativos em diferentes plataformas sem 
   a necessidade de um hardware adicional. Além disso, as VMs podem ser facilmente criadas, copiadas, movidas e excluídas.


2) Como funciona uma Máquia Virtual (VM)?

Resposta: Uma Máquina Virtual (VM) funciona como um computador simulado por software dentro de outro computador. 
          O hipervisor (VirtualBox) cria recursos virtuais (CPU, memória, disco, rede) que são usados por um sistema 
		  operativo convidado (Debian). Este sistema corre de forma isolada e independente, como se estivesse num hardware
		  real, mas todo o seu funcionamento é controlado pelo hipervisor, que gere o acesso aos recursos do computador físico 
		  (host), sem interferir diretamente com ele.

		  > uma VM funciona ao reproduzir virtualmente os componentes de hardware de um computador físico: CPU, RAM, armazenamento
		    e interfaces de rede, criando um ambiente virtualizado que se comporta como um computador físico.

Notas: 

=> Componentes principais de uma VM:

	> Hipervisor (ou monitor da máquina virtual):
	  
	- É o software responsável por criar, gerir, controlar e executar as máquinas virtuais. 
	- Permite que as VM usem os recursos do computador real (CPU, memória, disco, etc.) de forma 
	  segura e controlada.

	Tipo hosted: Corre sobre um sistema operativo já existente, como uma aplicação normal (como o VirtualBox). 
	  
	No projeto Born2beroot, utilizamos o VirtualBox (um hipervisor do tipo hosted) para criar uma VM 
	com o Debian e simular um servidor real num ambiente controlado.
	  
	> Hardware Virtualizado:

    - É a simulação dos componentes físicos de um computador dentro da VM. 
	  Embora os recursos sejam fornecidos pelo hardware real do sistema host, o hipervisor cria versões virtuais 
	  desses recursos para que o sistema operativo convidado os utilize como se fossem reais.
	- Exemplos de recursos virtualizados:

        > CPU virtual: A VM pensa que tem um ou mais processadores dedicados, mas na verdade são partilhados com o host.
		> Memória RAM virtual: O hipervisor aloca uma porção da RAM física à VM.
		> Disco rígido virtual (VHD/VDI): Um ficheiro no host simula um disco rígido físico dentro da VM.
		> Placa de rede virtual: Permite à VM aceder à internet e comunicar com outras máquinas (incluindo o host), como se 
		                         tivesse a sua própria interface de rede.
	  Estes recursos são simulados e partilhados com o host físico.
	  O ambiente isolado da VM garante que as operações dentro dela não afetam o sistema host, e vice-versa, ou seja, evita
	  que a VM utilize recursos além do que lhe foi atribuído.
	  
	> Sistema Operativo Convidado (Guest OS):

	- É o sistema operativo que corre dentro da VM, como se estivesse instalado num computador físico real. 
	  Ele comporta-se exatamente como se estivesse a correr diretamente sobre um hardware físico.
	- Funções do Guest OS:

        > Gere os utilizadores, ficheiros e permissões dentro da VM.
		> Comunica com o hardware virtual (que, por sua vez, é gerido pelo hipervisor).
	
	No projeto Born2beroot, o Debian é o sistema operativo convidado que instalamos na VM, e nele configuramos os utilizadores,
	grupos, sudo, UFW, SSH, cronjobs, e outras funcionalidades de administração de sistemas.

=> O “Ambiente isolado” significa que tudo o que acontece dentro da VM fica confinado a ela, não afeta o sistema onde ela está 
   instalada (o host), não partilha os processos, nem a memória, nem as permissões diretamente com o exterior.

	- A VM tem o seu próprio sistema operativo: Por exemplo, podemos ter o Windows no computador e a correr uma VM com o Debian.
	- A VM tem os seus próprios utilizadores, ficheiros, permissões, firewall, e serviços.
	- Se a VM for comprometida (por exemplo, com um vírus ou má configuração), isso não afeta o sistema host.
	- A VM comunica com o hardware virtual simulado pelo hipervisor.

3) Escolha do Sistema Operativo (Rocky vs Debian)

3.1) Diferenças entre o Rocky e o Debian:

Resposta: O Debian é uma distribuição Linux independente e comunitária, conhecida pela sua estabilidade, flexibilidade e 
          liberdade de configuração do software. Suporta uma ampla gama de arquiteturas e pode ser usado tanto em servidores
		  como em desktops. É ideal para quem procura um sistema leve, fiável e altamente personalizável. 
		  Usa pacotes .deb e o gestor de pacotes APT.

    	  Já o Rocky é uma distribuição baseada no Red Hat Enterprise Linux (RHEL), voltada para ambientes empresariais. 
		  Foca-se na estabilidade de longo prazo, segurança e compatibilidade empresarial. 
		  Utiliza pacotes .rpm e os gestores DNF/YUM.
    	  Ao contrário do Debian, o Rocky segue uma estrutura mais padronizada e controlada, ideal para 
		  empresas, mas com menos liberdade de personalização para o utilizador comum.

3.2) Por que escolhi o Debian para o projeto Born2beroot?

Resposta: Escolhi o Debian porque é uma distribuição estável, segura e altamente personalizável, ideal para aprender os 
          fundamentos da administração de sistemas Linux, como a gestão de permissões, serviços, utilizadores e políticas
		  de segurança.
		  Além disso, é leve, suporta uma vasta gama de pacotes livres e facilita a criação de um servidor Linux do zero, como o 
		  Born2beRoot exige.

4) Qual é o objetivo/propósito de uma VM? 

Resposta: O objetivo de uma VM é simular um sistema completo dentro de outro, permitindo executar um sistema operativo de forma 
		  isolada, segura e independente do sistema principal (host).
		  No projeto Born2beRoot, usamos a VM para criar um servidor Linux (Debian) onde configuramos e gerimos utilizadores,
		  permissões e serviços sem afetar o sistema real do computador.

          A VM possibilita-nos testar configurações, desenvolver e admnistrar sistemas ou executar múltiplos ambientes 
          diferentes no mesmo hardware físico, sem afetar o funcionamento do host. 

5) Diferença entre aptitude e apt e o que é APPArmor.

5.1) Diferença entre aptitude e apt

Resposta:  Ambos usam o sistema APT (Advanced Package Tool) na gestão de pacotes no Debian, mas têm abordagens diferentes:
    	  
          🔹 apt é um gestor de pacotes de nível inferior que utiliza comandos rápidos para instalar pacotes e é ideal para scripts 
		     e tarefas diretas na linha de comandos. Tem uma resolução de conflitos simples e não oferece sugestões de resolução
			 de conflitos complexos entre os pacotes.

    	  🔹 aptitude é um gestor de pacotes de nível superior, com uma interface mais interativa e uma lógica de resolução de 
		     conflitos mais avançada — tenta encontrar automaticamente várias formas de resolver os conflitos, o que torna útil
			 para a gestão complexa de pacotes.

Notas:
          
=> Ambos são gestores de pacotes .deb utilizados para instalar, atualizar ou remover programas em distribuições baseadas no Debian.
   Ambos utilizam o mesmo sistema por trás: o APT (Advanced Package Tool), que é o sistema de gestão de pacotes do Debian.
   APT é a base para ambos, é o sistema que faz realmente o trabalho de procurar, instalar, remover e atualizar pacotes .deb .
   Mas o APT não é utilizado diretamente pelo utilizador. Em vez disso, utilizamos ferramentas que funcionam por cima do APT, como 
   o apt e o aptitude.

=> Imaginemos que estamos a tentar instalar um programa, mas há um conflito de dependências (pacotes que são incompatíveis ou faltam).
   Com o apt, o comando pode simplesmente falhar e dizer “pacotes em conflito” ou “dependências não resolvidas”.
   Com o aptitude, ele pode dizer algo como: “Não consigo instalar diretamente, mas aqui estão 3 soluções possíveis. Queres remover
   este pacote e instalar outro? Ou instalar uma versão diferente?”
   Ou seja, o aptitude tenta encontrar uma solução automaticamente, o apt não.	
   

5.2) O que é o AppArmor?

Resposta: O AppArmor é um módulo de segurança do kernel do Linux que permite limitar o que cada aplicação pode fazer, mesmo com 
		  permissões de root. Funciona através de perfis de segurança que restringem o acesso a ficheiros e a recursos do sistema, 
		  apenas ao que é permitido pela sua política de segurança, ajudando a conter ataques e a reduzir o impacto de ataques ou
		  comportamentos inesperados.
	      É uma camada extra de proteção que torna o sistema mais seguro e controlado.

Notas:

=> É um módulo de segurança do kernel do Linux que permite ao admnistrador do sistema restringir o que cada programa pode fazer no
   sistema, mesmo que tenha permissões de root, de modo a limitar o que eles podem fazer no sistema.
   Ele permite definir perfis de segurança para aplicações, restringindo o que cada uma pode fazer no sistema, como aceder arquivos, 
   redes e recursos. O objetivo dele é o de conter os danos caso um programa seja comprometido, assim, mesmo que o programa tenha uma 
   falha ou vulneralidade ele fica confinado ao que o perfil permitir.
   O AppArmor é usado para proteger o sistema contra vulnerabilidades e ataques, limitando as ações das aplicações a um conjunto 
   específico de permissões.


6) O Avaliador vai avaliar se o script está a ser executado a cada 10 minutos.

7) Verificar se nenhuma interface gráfica está a ser utilizada.

   Aqui utilizaos o comando: # ls /usr/bin/*session                                                                              */

   E deverá aparecer: /usr/bin/dbus-run-session

8) Verificar se o serviço de UFW está ativo: 

   # sudo ufw status

   E deverá aparecer: Status: active

   # sudo service ufw status 

9) Verificar se o serviço SSH está ativo:

   # sudo service ssh status

   E deverá aparecer: Active: active (running)

10) Verificar qual o sistema operativo estamos a utilizar: 

   # uname -v   our   uname --kernel-version 

11) Verificar se o utilizador está dentro dos grupos "sudo" e "user42":

   # getent group sudo

   # getent group user42

   ou também

   # groups <username>

12) Verificar as regras de política de senha (password policy)

   # sudo chage -l <username>

   E deverá aparecer as seguintes linhas:
   
   PASS_MAX_DAYS   30 
   PASS_MIN_DAYS   2
   PASS_WARN_AGE   7

   PASS_MAX_DAYS 30: Define o número máximo de dias que uma senha pode ser usada antes de ser necessário trocá-la.
                     Neste caso, a senha expira 30 dias após ter sido definida.

   PASS_MIN_DAYS 2: Define o número mínimo de dias que o utilizador deve esperar antes de poder mudar a senha novamente.
                    Neste caso, o utilizador só poderá alterar a senha após 2 dias desde a última mudança.

   PASS_WARN_AGE 7: Define com quantos dias de antecedência o sistema começa a avisar o utilizador de que a senha está prestes
                    a expirar.

13) Explicar como as regras de senha foram configuradas:

   # vim /etc/pam.d/common-password

   Este path aponta para um ficheiro de configuração do sistema localizado na pasta /etc/pam.d .
   O /etc é onde ficam os ficheiros de configuração do sistema no Linux.
   A pasta /pam.d contém os ficheiros de configuração do PAM, que controla a autenticação dos utilizadores no sistema.

   O ficheiro common-password define como as senhas são tratadas e verificadas no sistema, especialmente durante a criação
   ou alteração de senhas com comandos como passwd.

   E deverá aparecer as seguintes linhas:

   minlen=10           -> Define o comprimento mínimo da senha. Aqui, a senha deve ter pelo menos 10 caracreres.

   ucredit=-1          -> Obriga o uso de letras maiúsculas. O valor negativo indica o número minimo de ocorrencias.
                          Assim, a senha deve ter pelo menos uma letra maiúscula ([U]ppercarse)
   dcredit=-1          -> Obrigada o uso de números. Assim a senha deve conter pelo menos um número ([D]igit)

   lcredit=-1          -> Obriga o uso de letras minúsculas. A senha deve ter pelo menos uma letra minúscula ([L]owercase)
   
   maxrepeat=3         -> Impede repetições consecutivas de caracteres iguais. A senha não pode ter mais do que 3 caracteres 
                          repetidos seguidos (ex: aaa123)

   reject_username     -> Impede que a senha seja igual o nome do utilizador.

   difok=7             -> Define o mínimo de caracteres diferentes em relação à senha anterior.
                          A nova senha deve ter pelo menos 7 caracteres diferentes da senha anterior.
   enforce_for_root    -> Faz com que as regras também se apliquem ao utilizador root.
                          Sem esta opção, o root poderia usar senhas fracas.

14) Criar um novo utilizador e mostrar que segue a política de senha que criamos

   # sudo adduser newuser

   E introduzimos uma senha que segue a política de senha que criamos anteriormente.

   NOTE: To delete a certain user we use:  # sudo deluser <username>

15) Criamos um novo grupo chamado "evaluating"

   # sudo addgroup evaluating
          
   NOTE: To delete a certain group we use:  # sudo delgroup <groupname> 

16) Adicionar o utilizador "newuser" ao grupo "evaluating":

   # sudo adduser newuser evaluating 

17) Verificar se o utilizador "newuser" foi adicionado corretamente ao grupo "evaluating":

	# getent group evaluating

	ou também

	# groups newuser

18) Explicar as vantagens da política de senhas e vantagens e desvantagens da implementação de politicas: 

Resposta: A política de senhas tem como objetivo reforçar a segurança do sistema, garantindo que as senhas sejam fortes e dificeis
          de adivinhar.Isto ajuda a prevenir ataques de força bruta e reduz o risco de acesso não autorizado ao sistema.

		  Vantagens: - Aumenta a segurança geral do sistema: obriga os utilizadores a escolherem senhas fortes, reduzindo o risco 
		               de acessos indevidos.
		             - Protege contra ataques de força bruta e acesso não autorizado: Senhas complexas tornam esses ataques mais 
					   dificeis de serem bem-sucedidos.
					 - Diminui o uso de senhas comuns e previsíveis: As regras de complexidade forçam os utilizadores a criar 
					   senhas mais únicas e difíceis de adivinhar.
		             - Reduz falhas causadas por senhas fracas: Evita que os utilizadores reutilizem senhas fracas ou demasiado 
					   simples.

    	  Desvantagens: - Políticas muito rígidas podem causar frustração nos utilizadores.
		                - Risco de comportamentos inseguros: os utilizadores para não esquecerem da senha, podem escrevê-la em 
						  locais inseguros.
						- Políticas muito rígidas podem levar à repetição da mesma senha em vários serviços, o que diminui a 
						  segurança.
						- Falsa sensação de segurança.

Notas:

=> Em teoria, o principal benefício das regras de complexidade da senha é que elas impõem o uso de senhas exclusivas que são mais 
   difíceis de quebrar. Quanto mais requisitos aplicarmos, maior o número de combinações possíveis de letras, números e caracteres.
   As regras de complexidade de senha tentam impor esse requisito de “difícil de quebrar”, mas nem sempre são bem-sucedidas. 
   Isso se resume, em parte, com a diminuição dos retornos envolvidos no aumento da complexidade.


19) Verificar se o o nome do host da máquina está correto - login42:

	# hostnamectl

	E deverá aparecer: rmedeiro42

20) Modificar o nome do host para substituir o meu login pelo do avaliador: 

	# sudo hostnamectl set-hostname student42

	E substituímos o nosso login para o do avaliador, por exemplo "rmedeiro42" para "student42"

	Depois fazemos # sudo reboot

21) Verificar se o nome do host foi alterado corretamente:

	# hostnamectl
	
22) Restaurar o nome do host original

	# sudo hostnamectl set-hostname rmedeiro42

	E substituímos o nome do host para o original, por exemplo "student42" para "rmedeiro42"

	Depois reiniciamos a máquina: # sudo reboot

23) Verificar se todas as partições estão indicadas de acordo com o subject: 

	# lsblk

24) Breve explicação de como funciona a LVM: 

Resposta: O LVM (Logical Volume Manager) funciona como uma camada entre o sistema operativo e os discos físicos, permitindo criar
          volumes lógicos flexíveis em vez de partições fixas. Primeiro, os discos ou partições físicas são convertidos em volumes
		  físicos (PVs). Estes volumes físicos (PVs) são agrupados em grupos de volume (VGs), e dentro destes grupos são criados os
		  volumes lógicos (LVs), que funcionam como partições normais. Esta estrutura permite redimensionar, mover ou criar 
		  partições de forma dinâmica, mesmo com o sistema em funcionamento, o que é muito útil para ambientes de servidor. 
		  
          Com o LVM, podemos agrupar vários discos físicos num único volume lógico, facilitando a expansão do espaço de 
		  armazenamento conforme necessário. 
        
		  No Born2beRoot, usamos o LVM para dividir e gerir o disco de forma modular e organizada, permitindo modificar o espaço 
		  das partições sem formatar nem reiniciar o sistema. 

Notas:

=> No projeto Born2beRoot, usar LVM permite-nos configurar volumes lógicos específicos para /home, /var, etc., facilitando a organização 
   e a gestão do espaço em disco, além de dar uma visão prática de como gerir o armazenamento num servidor real.
		  

O que é o LVM?

Resposta: O LVM (Logical Volume Manager) é um sistema de gestão de volumes no Linux que permite organizar o armazenamento de 
          forma mais flexível e dinâmica, o que é especialmente útil em ambientes de servidores. 
		  Em vez de dividir um disco rígido em partições fixas, o LVM permite criar volumes lógicos que podem ser redimensionados,
		  movidos ou agrupados dinamicamente, sem necessidade de formatar ou reiniciar o sistema. 

		  Fornece um método de atribuição de espaço em dispositovs de armazenamento, que é mais flexível do que os esquemas 
		  convencionais de partição para armazenamento de volumes.


25) Verificar se o sudo está instalado corretamente: 

	# which sudo

	E deverá aparecer: /usr/bin/sudo

	Ou utilizar o comando:

	# dpkg -l | grep sudo

	OU ainda:

	# dpkg -s sudo

26) Vamos atribuir o novo utilizador "newuser" no grupo sudo: 

	# sudo adduser newuser sudo

	Vamos ver o que está dentro do grupo sudo:

	# getent group sudo

27) Explicar o valor e operação do comando sudo:

Resposta: O comando sudo (SuperUser DO) permite a um utilizador executar comandos com privilégios de administrador (root) sem 
		  precisar de iniciar a sessão como root. Por padrão, o Linux restringe o acesso a certas partes do sistema que impedem
		  que os arquivos confidenciais sejam comprometidos. O comando sudo eleva temporariamente os privilégios que permitem os 
		  utilizadores de completar tarefas admnistratrivas sem fazer login como uitlizador root.
		  
		  Ele é essencial para realizar tarefas admnistrativas que requerem permissões elevadas como instalar software ou alterar 
		  configurações do sistema, garantindo maior segurança ao limitar o uso direto da conta root e controlar os acessos através
		  do ficheiro /etc/sudoers.

NOtas:

=> A diferença entre o sudo e o root está no acesso e na maneira como os priviléfios admnistrativos são utilizados.

   Root (admnistrador): É o utilizador administrador absoluto do sistema.
                        Tem acesso total a todos os arquivos, comandos e configurações.
                        Pode fazer qualquer coisa no sistema — inclusive acidentalmente danificá-lo.
                        Geralmente não é recomendado fazer login diretamente como root, por motivos de segurança.

  Sudo (superuser do): É um comando que permite a um utilizador executar comandos como root, sem fazer login como root.
                       Exige que o utilizador esteja na lista de permissões (normalmente no grupo sudo).
                       Permite executar apenas comandos específicos com privilégios elevados.
					   É mais seguro do que usar diretamente o root, pois:  Regista os comandos no log (/var/log/sudo)
																			Pode limitar o que o usuário pode fazer via /etc/sudoers

28) Mostramos a aplicação das regras impostas para o sudo (sudoers file): 

	# cd /var/log/sudo 
	
	# sudo visudo   ou   # vim /etc/sudoers.d/sudoconfig

	A pasta /var/log/sudo é o local onde são armazenados os registos (logs) detalhados de tudo o que é feito com o sudo.

	O comando sudo visudo é a forma segura de editar o sudoers file.

	O sudoers file define quem pode usar o comando sudo, com que permissões e em que condições.
	Ele contém as regras de controlo de acesso priveligiado.

	Por que usar sudo visudo: > O visudo verifica a sintaxe do ficheiro antes de salvar.
                                Se houver um erro, ele impede que o ficheiro seja salvo com esse erro.
                                Isso evita que o sistema fique travado ou sem permissões administrativas.

        					  > Se editarmos o /etc/sudoers manualmente e colocarmos uma linha errada, podemos perder 
							    completamente o acesso ao sudo.
								Isso pode impedir qualquer administração do sistema sem entrar como root por outros meios 
								(por exemplo, no modo de recuperação).

	Defaults  secure_path  -> :/snap/bin foi adicionado ao fim para permitir executar aplicações snap com sudo
							   Define o caminho das pastas onde o sudo procura por comandos executáveis. 
							   Evita que os comandos maliciosos fora dos caminhos padrão sejam executados com privilégios de root.
	Defaults  badpass_message="Wrong Password!"     -> Personaliza a mensagem mostrada quando uma senha incorreta é inserida ao
	                                                   usar o sudo
	Defaults  passwd_tries=3                        -> Define o número de tentativas permitidas para inserir a senha correta ao
	                                                   usar o sudo. Previne ataques de força bruta. Após 3 erros o comando falha.
	Defaults  iolog_dir="/var/log/sudo"             -> Define a pasta onde serão guardadas as entradas e saídas de comandos executados
	                                                   via sudo (input/output logs)
	Defaults  logfile="/var/log/sudo/sudo.log"      -> Define o caminho do ficheiro (sudo.log) onde as ações feitas com sudo são
	                                                   registadas (quem usou o sudo, quando, e para quê)
	Defaults  log_input                             -> Ativa o registo de tudo o que for escrito durante a execução do comando sudo.

	Defaults  log_output                            -> Ativa o registo de toda a saída dos comandos executados com o sudo.

	Defaults  requiretty                            -> Exige que o comando sudo seja executado a partir de um terminal (tty).
	                                                   Evita que o sudo seja usado em scripts automáticos.

29) Verificar se a pasta /var/log/sudo existe e se o ficheiro sudo.log está lá:

	# sudo ls /var/log/sudo/

	E deverá aparecer: sudo.log

	# cat sudo.log 

	Aqui deverá aparecer o histórico de execuções do comando sudo
	
	Portanto, deveremos executar qualquer comando que utilize o sudo e verificar se houve alguma alteração
	no ficheiro sudo.log.

30) Verificar o conteúdo dos arquivos nesta pasta: 

	# sudo ls /var/log/sudo/00/00

	# sudo ls /var/log/sudo/00/00/<newfolder>

31) Verificar se há um histórico de comandos utilizando o sudo:

	# sudo cat /.../log   (input log)

	#sudo cat /.../ttyout  (output log)

32) Executar um comando utilizando o sudo e verificar se os arquivos são atualizados: 

	# sudo apt update

	# sudo ls /var/log/sudo/00/00   (deverá ter uma nova pasta)


33) Verificar se o programa UFW está instalado na VM e verifica se ele funciona corretamente:

	# dpkg -l | grep ufw

	# sudo service ufw status   ou    # sudo ufw status

	Porquê que aparecem regras com v6? 

	As regras com v6 referem-se ao protocolo IPv6, enquanto que as regras sem, referem-se ao protocolo IPv4.

	IPv4 vs IPv6: IPv4: formato de IP tradicional (ex: 192.168.1.1)
                  IPv6: novo formato (ex: 2001:0db8:85a3::8a2e:0370:7334)
				  Criado para substituir o IPv4 e suportar muito mais endereços.

34) Explicar o que é UFW :

Resposta: O UFW (Uncomplicated Firewall) é uma interface de linha de comando que foi projetada para facilitar a gestão de regras 
          do firewall, tornando mais simples para os utilizadores protegerem os seus sistemas contra o tráfego indesejado. 
		  O UFW permite que os utilizadores criem regras de firewall para permitir ou bloquear conexões de rede com base nos 
		  endereços IP, portas e protocolos, ajudando a proteger o sistema contra ataques e acessos não autorizados.

		  O iptables permite definir regras para controlar o tráfego de rede que entra, sai ou passa pelo sistema.
		  Essas regras determinam o que pode ou não pode passar, com base em critérios como o IP, portas e protocolos.


35) Listar as regras ativas na UFW (se a parte do bónus não for feita, apenas a regra da porta 4242 deve aparecer):

	# sudo ufw status numbered

36) Criar uma nova regra para a porta 8080. Verifique se ele foi adicionado às regras ativas e, de seguida, podemos excluí-lo:

	# sudo ufw allow 8080

	# sudo ufw status numbered

	# sudo ufw delete <rule number>


37) Verificar se o serviço ssh está instalado na VM: 

	# which ssh   ou    # dpkg -l | grep openssh-server

	E deverá aparecer: /usr/bin/ssh

38) Verificar se o serviço ssh está a correr:

	# sudo service ssh status

	E deverá aparecer: Active: active (running)
    
	E confirmamos se o serviço está a correr na porta 4242.

	Aqui para confirmar se usa apenas a porta 4242, podemos usar o comando:

	# sudo service ssh status | grep listening

39) Explicar o que é o SSH: 

Resposta: O SSH (Secure Shell) é um protocolo de rede que permite a comunicação segura entre dois computadores, geralmente para 
		  acesso remoto em sistemas Linux. Ele fornece uma conexão criptografada, garantindo que os dados transmitidos entre o 
		  cliente e o servidor estejam protegidos contra ataques e interceptação. 

		  O SSH é amplamente utilizado para administração remota de servidores, transferência segura de arquivos e execução de
		  comandos em sistemas remotos, oferecendo autenticação forte e controle de acesso.

		
40) Utilizar a ssh para fazer login com o utilizador "rmedeiro" na máquina virtual:

	# # hostname -I

	# ssh newuser@<VirtualMachine_IP> -p 4242

41) Certificar que não podemos fazer login SSH com o utilizador root: 

    rmedeiro@rmedeiro42:~$ login root

	e aparece a mensagem: "Cannot possibly work without effective root"

42) Explicação do script: 

42.1) Arquitetura do sistema:

    arch=$(uname -a)

	> uname: É um comando que mostra as informações sobre o sistema.
	> -a: É uma opção que mostra todas as informações disponíveis:

		- kernel name			Nome do sistema (ex: Linux)
        - nodename				Nome da máquina na rede
        - kernel release		Versão do kernel (ex: 5.15.0-105-generic)
        - kernel version		Data e compilação do kernel
        - machine				Arquitetura do processador (ex: x86_64)
        - processor				Tipo do processador
        - hardware platform		Plataforma de hardware (nem sempre aparece)
        - operating system		Nome do SO (ex: GNU/Linux)

	arch=$(...): Executa o comando dentro dos parênteses e atribui o resultado à variável arch.
	             Assim, a variável arch agora contém toda a informação que uname -a devolveu.

    printf "#Architecture: $arch\n" - Imprime essas informações.

	> printf: É semelhante ao echo, mas permite uma formatação avançada, como casas decimais, alinhamento, e controle de strings.
	> #Architecture:: Texto fixo, usado como rótulo.
	> $arch: Conteúdo da variável arch, ou seja, a saída de uname -a.

    Exemplo de output: #Architecture: Linux myhost 5.15.0-105-generic #115-Ubuntu SMP Mon Apr 1 15:37:47 UTC 2024 x86_64 x86_64 x86_64 GNU/Linux


42.2) Número de CPUs físicas:

    pcpu=$(cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l)

	Este comando recolhe o número de CPUs físicas presentes na máquina.

	> cat /proc/cpuinfo: 

          - /proc/cpuinfo: é um ficheiro virtual que contém as informações detalhadas sobre os processadores
		                   (tais como, os cores, as threads, o modelo, etc).
		  - cat: lê o conteúdo desse ficheiro e envia o texto para o próximo comando no pipe ( | ).

	> grep "physical id": Filtra as linhas que contêm physical id, ou seja, o identificador de cada CPU física.

	        Exemplo de output: physical id : 0
							  physical id : 0
							  physical id : 1
							  physical id : 1

	> sort: Ordena as linhas ( é necessário para que o uniq funcione corretamente).
	> uniq: Remove linhas duplicadas consecutivas.

			Exemplo de output: physical id : 0
							   physical id : 1

	> wc -l: Conta o número de linhas, ou seja, conta quantos CPUs físicos existem.
	         Aqui, cada linha representa uma CPU física única.

			 No exemplo acima, a contagem será 2, indicando que tem dois processadores físicos.

	printf "#CPU physical: $pcpu\n"

	Exemplo de output: #CPU physical: 2

42.3) Número de CPUs lógicas (vCPUs): 

    vcpu=$(cat /proc/cpuinfo | grep "processor" | sort | uniq | wc -l)

	Este comando serve para contar o número de CPUs lógicas vísiveis pelo sistema operativo.

    > cat /proc/cpuinfo: 

          - /proc/cpuinfo: é um ficheiro virtual que contém as informações detalhadas sobre os processadores
		                   (tais como, os cores, as threads, o modelo, etc).
		  - cat: lê o conteúdo desse ficheiro e envia o texto para o próximo comando no pipe ( | ).

	> grep "processor": Filtra as linhas que contêm a palvra processor, que neste ficheiro indica um identificador
	                    de unidade lógica de CPU.

			Exemplo:  processor   : 0
					  processor   : 1
					  processor   : 2
					  processor   : 3

			Cada linha representa uma vCPU (CPU lógica)

	> sort: Ordena as linhas ( é necessário para que o uniq funcione corretamente).
	> uniq: Remove linhas duplicadas consecutivas.
	> wc -l: Conta o número de linhas restantes, ou seja, quantas entradas de processor únicas existem.
             Este número corresponde ao total de vCPUs (CPUs lógicas), visíveis e utilizáveis pelo kernel.

			 Por exemplo: Num sistema com 2 CPUs físicas, cada uma com 4 núcleos, e Hyper-Threading ativado 
			              (2 threads por núcleo):

        				  Total de vCPUs = 2 × 4 × 2 = 16

	printf "#vCPU: $vcpu\n"

	Exemplo de output: #vCPU: 16

42.4) Uso de Memória RAM:

	fram=$(free -m | grep Mem | awk '{print $2}')

	Aqui, obtemos a quantidade total de memória RAM (em MB).

	> free -m: este comando mostra o uso de memória RAM do sistema (em MB, devido à flag -m).
	> grep Mem: Filtra a linha com a palavra Mem, ou seja, a linha que mostra os dados da RAM.
	> awk '{print $2}': Extrai a 2ª coluna dessa linha, que representa a memória total.

	Resultado: Vai armazenar na variável fram a quantidade total de memória RAM, em MB.

	uram=$(free -m | grep Mem | awk '{print $3}')

	Aqui, obtemos a quantidade de memória atualmente usada (em MB).

	> free -m: este comando mostra o uso de memória RAM do sistema (em MB, devido à flag -m).
	> grep Mem: Filtra a linha com a palavra Mem, ou seja, a linha que mostra os dados da RAM.
	> awk '{print $3}': Extrai a 3ª coluna, que representa a memória usada.

	Resultado: Armazena na variável uram o total de memória RAM em uso.

	pram=$(free -m | grep Mem | awk '{print $3/$2 * 100}')

	Aqui, calculamos a percentagem de RAM em uso.

	> free -m: este comando mostra o uso de memória RAM do sistema (em MB, devido à flag -m).
	> grep Mem: Filtra a linha com a palavra Mem, ou seja, a linha que mostra os dados da RAM.
	> awk '{print $3/$2 * 100}': Extrai a 3ª coluna, que representa a memória em uso e divide
	                             o valor usado pela memória total e multiplica por 100 para obter
								 a percentagem de uso da RAM.

	Resultado: Armazena na variável pram a percentagem de RAM em uso, com casas decimais.

	printf "#Memory Usage: $uram/$fram%s (%.2f%%)\n" "MB" "$pram"

	Exemplo de output: #Memory Usage: 2234/7973MB (28.02%)

42.5) Uso de Disco:

	sdisk=$(df -h --total | awk END'{print $2}' | cut -d G -f1)

	Aqui, obtemos o total de espaço em disco.

	> df -h --total: - df: Mostra o uso do disco (espaço usado e available)
	                 - h: Mostra os tamanhos em formato legível (ex: G para gigabytes).
					 - --total: Adiciona uma linha final com o total acumulado de todas as partições.

					 Exemplo: 

					 Filesystem      Size  Used Avail Use% Mounted on
					  /dev/sda1       50G   15G   35G  30%     /
					  tmpfs           2.0G     0  2.0G  0%  /dev/shm
						...
					  total            70G   25G   45G  36%

	> awk END'{print $2}': Extrai a última linha (graças ao END) e imprime a segunda coluna: o total de espaço.
	> cut -d G -f1: corta o G final para extrair apenas o número.

	Resultado: Armazena na variável sdisk o espalo total em disco, em gigabytes.

	udisk=$(df -h --total | awk END'{print $3}' | cut -d G -f1)

	Aqui, obtemos o total de espaço utilizado em disco.

	> df -h --total: - df: Mostra o uso do disco (espaço usado e available)
	                 - h: Mostra os tamanhos em formato legível (ex: G para gigabytes).
					 - --total: Adiciona uma linha final com o total acumulado de todas as partições.
	> awk '{print $3}': Extrai a 3ª coluna, que é o espaço usado.
	> cut -d G -f1: corta o G final para extrair apenas o número.

	Resultado: Armazena em udisk o espaço utilizado, em GB.

	pdisk=$(df -h --total | awk END'{print $3/$2 * 100}')

	Aqui, obtemos a percentagem de disco usado.

	> df -h --total: - df: Mostra o uso do disco (espaço usado e available)
	                 - h: Mostra os tamanhos em formato legível (ex: G para gigabytes).
					 - --total: Adiciona uma linha final com o total acumulado de todas as partições.
	> awk END'{print $3/$2 * 100}': divide o espaço usado pelo total e multiplica por 100 para obter a percentagem.

	Resultado: Armazena na variável pdisk a percentagem do espaço em disco usado.

	printf "#Disk Usage: $udisk/$sdisk%s (%.2f%%)\n" "Gb" "$pdisk"

	Exemplo de saída: #Disk Usage: 25/70Gb (35.71%)

42.6) Carga da CPU:

	cpul=$(mpstat | tail -n 1 | awk '{print 100-$NF}')

	Aqui, calculamos a carga atual da CPU, ou seja, quanto da CPU está a ser usada.

	> mpstat: Exibe estatísticas de uso da CPU.
	> tail -n 1: Pega apenas a última linha da saída, que é a que contém os dados mais recentes
	             de uso da CPU.

	printf "#CPU load: %.1f%%\n" "$cpul"

	Exemplo de output: #CPU load: 4.0%


42.7) Último Boot:

	boot=$(who -b | awk '{print $3" "$4}')

	Aqui, obtemos a data e a hora do último boot.

	> who -b: Exibe apenas quando o sistema foi iniciado pela última vez.

	          Exemplo:  system boot  2025-05-24 09:14

	> awk '{print $3" "$4}': Extrai o 3º e 4º campos da linha: - $3 -> a data do último boot.
	                                                           - $4 -> a hora do último boot.

	printf "#Last boot: $boot\n"

	Exemplo de output: #Last boot: 2025-05-24 09:14


42.8) Uso de LVM:	

	lvm=$(lsblk | grep "lvm" | wc -l)
	if [ $lvm -eq 0 ]
	then
        printf "#LVM use: no\n"
	else
        printf "#LVM use: yes\n"
	fi

	> lsblk: Mostra todos os dispositivos de blocos (discos, partições, volumes).
	> grep "lvm": Filtra apenas as linhas que contenham "lvm", ou seja, os volumes gerenciados pelo LVM.
	> wc -l: Conta quantas linhas foram encontradas.

	O valor final será o número de volumes LVM encontrados.

	Por exemplo: - Se houver LVM: lvm=2
	             - Se não houver LVM: lvm= 0

	> if [ $lvm -eq 0 ]: Verifica se o valor de lvm é igual a zero (ou seja, nenhum volume LVM encontrado).
	> Se for zero: - printf "#LVM use: no\n"
	> Caso contrário: - printf "#LVM use: yes\n"

42.9) Conexões TCP ativas:

	ctcp=$(ss | grep "tcp" | wc -l)

	Conta quantas conexões TCP estão atualmente ativas no sistema.

	> ss: Exibe todas as conexões abertas no sistema, bem como portas em escuta.
	> grep "tcp": Filtra as linhas que contêm o protocolo TCP.
	> wc -l: Conta quantas linhas foram devolvidas pelo grep. Cada linha representa uma conexão TCP.

		  - ss: MOstra conexões de rede.
		  - grep "tcp": Filtra conexões TCP.
		  - wc -l: Conta quantas conexões existem.
	
	printf "#Connections TCP: $ctcp %s\n" "ESTABLISHED"

42.10) Número de utilizadores ligados:

	usr=$(users | wc -w)

	> users: Lista utilizadores que estão logados.
	> wc -w: Conta quantos utilizadores estão logados.

	printf "#User log: $usr\n"

42.11) Endereço IP e MAC:

	ip=$(hostname -I | awk '{print $1}')

	Obtém o endereço IP principal do computador.

	> hostname -I: Lista os endereços IP.
	> awk '{print $1}': Extrai apenas o primeiro endereço IP da lista.

	mac=$(ip address | grep "ether" | awk '{print $2}')

	Obtém o endereço MAC.

	> ip address: Lista todas as interfaces de rede e os seus detalhes.
	> grep "ether": Filtra somente as linhas que contêm o endereço MAC, que estão indicadas pela palavra ether.

					Exemplo: link/ether 00:1a:2b:3c:4d:5e brd ff:ff:ff:ff:ff:ff
							 link/ether 11:22:33:44:55:66 brd ff:ff:ff:ff:ff:ff

	> awk '{print $2}': Extrai o endereço MAC.

	                    Exemplo: 00:1a:2b:3c:4d:5e

	printf "#Network: IP $ip ($mac)\n"

42.12) Número de comandos sudo usados:

	sudo=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)

	Exibe o número de comandos sudo executados registados no log.

	> cat /var/log/sudo/sudo.log: Exibe o conteúdo do ficheiro sudo.log, onde ficam registados os comandos que foram 
	                              executados usando o sudo.
	> grep "COMMAND": Filtra as linhas que contêm a palavra COMMAND.
	                  Essas linhas indicam comandos sudo executados.
	> wc -l: Conta o número total de linhas, ou seja quantas vezes foi registado um comando sudo executado.

	printf "#Sudo: $sudo\n"

43) Explicar o que é o cron: 

Resposta: O cron é um serviço do sistema Linux que permite agendar a execução de tarefas (scripts ou comandos) em intervalos 
          regulares. 
		  Ele utiliza um arquivo de configuração chamado "crontab" para definir quais comandos devem ser executados, quando e 
		  com que frequência. 
		  O cron é amplamente utilizado para automatizar tarefas administrativas garantindo que essas tarefas sejam executadas 
		  automaticamente sem a necessidade de intervenção manual.

44) Modificar o tempo de execução do script de 10 minutos para 1 minuto:

	# sudo crontab -u root -e

	E alteramos a linha: 

	*/10 * * * * root /usr/bin/monitoring.sh

	Para:

	*/1 * * * * root /usr/bin/monitoring.sh

45) Finalmente, fazemos o script parar de funcionar quando o servidor tiver começado, mas sem modificar o script:

	# sudo /etc/init.d/cron stop         ou         # sudo systemctl stop cron

	Se quisermos que ele volte a correr: 

	# sudo /etc/init.d/cron start        ou          # sudo systemctl start cron
