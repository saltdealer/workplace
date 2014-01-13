#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h> 
#include <linux/sched.h>
#include <linux/tty.h>

static int __init lkp_init(void);
static int __exit lkp_exit(void);

void tty_write_message1(struct tty_struct *, char *);

static int __init lkp_init(void)
{
    printk("<1>Hello ,Word! p_pid%d(%s)  pid %d(%s)\n", current->parent->pid, current->parent->comm,
                current->pid, current->comm);
    struct task_struct *pos;
    struct list_head *current_head;
    int count =0;
    current_head = &(current->tasks);
    list_for_each_entry(pos,current_head,tasks)
    {
        count ++;
        tty_write_message1(current->signal->tty,msg1);
        printk(" precess %d,%s\'s pid is %d\n",count,pos->comm,pos->pid);
    }

//    char *msg = "hello tty!\n";
//   tty_write_message1(current->signal->tty,msg); 
    return 0;
}

static int __exit lkp_exit(void)
{
    printk("<2>Hello,Word exit\n");
}

void tty_write_message1(struct tty_struct *tty ,char *msg)
{
    if(tty && tty->driver->ops->write)
      tty->driver->ops->write(tty,msg,strlen(msg));
    return ;
}

module_init(lkp_init);
module_exit(lkp_exit);


