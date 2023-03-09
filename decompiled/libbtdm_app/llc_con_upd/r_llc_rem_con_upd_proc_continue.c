/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_rem_con_upd_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_con_upd_proc_continue(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  char cVar2;
  undefined2 uVar3;
  void *__src;
  int iVar4;
  undefined4 *__dest;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  int iVar6;
  
  __src = (void *)(**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  if (param_2 == 0xb) {
    (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0xb,*(code **)(_r_ip_funcs_p + 0x684));
    (**(code **)(_r_ip_funcs_p + 0x3c8))
              (param_1,*(undefined2 *)(iVar6 + 0xe),*(code **)(_r_ip_funcs_p + 0x3c8));
  }
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x680))(__src,*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar4 != param_2) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0x10);
    param_1 = (**(code **)(_r_ip_funcs_p + 0x680))(__src,*(code **)(_r_ip_funcs_p + 0x680));
    uVar5 = 0x1e7;
_L81:
                    /* WARNING: Could not recover jumptable at 0x0001070e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,param_2,"llc_con_upd.c",uVar5);
    return;
  }
  cVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(__src,*(code **)(_r_ip_funcs_p + 0x680));
  switch(cVar2 + -7) {
  case '\0':
_L72:
    *(ushort *)(iVar6 + 0x42) = *(ushort *)(iVar6 + 0x42) | 0x10;
    if (*(char *)((int)__src + 0x2c) == '\0') {
      uVar1 = *(ushort *)(iVar6 + 0xe);
      if (((uVar1 < *(ushort *)((int)__src + 8)) || (*(ushort *)((int)__src + 10) < uVar1)) ||
         (*(int *)((int)__src + 0xc) != *(int *)(iVar6 + 0x10))) {
        (**(code **)(_r_ip_funcs_p + 0x5ec))
                  (param_1,*(undefined2 *)((int)__src + 0xc),*(undefined2 *)((int)__src + 0xe),
                   *(code **)(_r_ip_funcs_p + 0x5ec));
        (**(code **)(_r_ip_funcs_p + 0x684))(__src,param_1,8,*(code **)(_r_ip_funcs_p + 0x684));
        *(undefined1 *)((int)__src + 0x2e) = 1;
        return;
      }
      *(ushort *)((int)__src + 8) = uVar1;
      *(ushort *)((int)__src + 10) = uVar1;
      goto _L71;
    }
    param_3 = (**(code **)(_r_ip_funcs_p + 0x378))
                        (param_1,*(undefined1 *)((int)__src + 0x26),
                         *(undefined2 *)((int)__src + 0x22),*(undefined2 *)((int)__src + 0x28),
                         *(undefined2 *)((int)__src + 0xc),*(undefined2 *)((int)__src + 0xe),
                         *(undefined2 *)((int)__src + 0x24),*(code **)(_r_ip_funcs_p + 0x378));
    if (param_3 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000107ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x684))(__src,param_1,10);
      return;
    }
    break;
  case '\x01':
_L71:
    if (param_3 == 0) {
      if ((*(ushort *)(iVar6 + 0x42) & 1) == 0) {
        uVar3 = (**(code **)(_r_ip_funcs_p + 0x338))(param_1,*(code **)(_r_ip_funcs_p + 0x338));
        iVar6 = _r_ip_funcs_p;
        *(undefined2 *)((int)__src + 0x14) = uVar3;
        (**(code **)(iVar6 + 0x5fc))(param_1,__src,*(code **)(iVar6 + 0x5fc));
        *(undefined2 *)((int)__src + 0x16) = *(undefined2 *)((int)__src + 0x2a);
        llc_ll_connection_param_rsp_pdu_send(param_1,__src);
        (**(code **)(_r_ip_funcs_p + 0x684))(__src,param_1,9,*(code **)(_r_ip_funcs_p + 0x684));
        (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,1,*(code **)(_r_ip_funcs_p + 0x68c));
                    /* WARNING: Could not recover jumptable at 0x00010850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x3c8))(param_1,*(undefined2 *)((int)__src + 8));
        return;
      }
      __dest = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x10b,param_1 << 8 | 1,0x30,*(code **)(_r_modules_funcs_p + 200));
      memcpy(__dest,__src,0x30);
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
      *__dest = *(undefined4 *)(_r_ip_funcs_p + 0x5f8);
      (*UNRECOVERED_JUMPTABLE)(__dest,param_1,1,UNRECOVERED_JUMPTABLE);
      (**(code **)(_r_modules_funcs_p + 0xe0))(__dest,*(code **)(_r_modules_funcs_p + 0xe0));
    }
    else {
      (**(code **)(_r_ip_funcs_p + 0x5bc))(param_1,0xf,param_3,0,*(code **)(_r_ip_funcs_p + 0x5bc));
    }
    goto _L78;
  case '\x02':
    if (param_3 == 0) {
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
      *(undefined1 *)((int)__src + 0x2c) = 1;
      goto _L72;
    }
    break;
  case '\x03':
  case '\x04':
    break;
  default:
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
    param_2 = (**(code **)(_r_ip_funcs_p + 0x680))(__src,*(code **)(_r_ip_funcs_p + 0x680));
    uVar5 = 0x264;
    goto _L81;
  }
  (**(code **)(_r_ip_funcs_p + 0x5f0))(param_1,param_3,__src,*(code **)(_r_ip_funcs_p + 0x5f0));
  *(ushort *)(iVar6 + 0x42) = *(ushort *)(iVar6 + 0x42) & 0xffef;
_L78:
                    /* WARNING: Could not recover jumptable at 0x000108fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1);
  return;
}

