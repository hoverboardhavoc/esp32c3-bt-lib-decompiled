/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_rem_encrypt_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_encrypt_proc_continue(uint param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  code *UNRECOVERED_JUMPTABLE;
  int iVar6;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar3 != param_2) {
    if ((param_2 != 0x13) || (param_3 == 0x3d)) {
      param_3 = 0x3d;
      (**(code **)(_r_ip_funcs_p + 0x55c))(param_1,0x3d,1,*(code **)(_r_ip_funcs_p + 0x55c));
    }
    goto _L54;
  }
  cVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar2,*(code **)(_r_ip_funcs_p + 0x680));
  switch(cVar1 + -10) {
  case '\0':
    (**(code **)(_r_ip_funcs_p + 0x328))(param_1,0,*(code **)(_r_ip_funcs_p + 0x328));
    (**(code **)(_r_ip_funcs_p + 0x688))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x688));
    if ((uint)*(byte *)(iVar2 + 0x3a) != ((int)(uint)*(ushort *)(iVar6 + 0x42) >> 5 & 1U)) {
      (**(code **)(_r_ip_funcs_p + 0x5bc))
                (param_1,3,0x24,*(undefined4 *)(_r_ip_funcs_p + 0x58c),
                 *(code **)(_r_ip_funcs_p + 0x5bc));
      (**(code **)(_r_ip_funcs_p + 0x684))(iVar2,param_1,0x12,*(code **)(_r_ip_funcs_p + 0x684));
    }
    if (*(char *)(iVar2 + 0x3a) == '\0') {
      (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,2,*(code **)(_r_ip_funcs_p + 0x664));
      (**(code **)(_r_ip_funcs_p + 0x584))(param_1,*(code **)(_r_ip_funcs_p + 0x584));
      uVar4 = 0xd;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
      goto _L84;
    }
    (**(code **)(_r_ip_funcs_p + 0x3a0))(param_1,0,*(code **)(_r_ip_funcs_p + 0x3a0));
    (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,1,*(code **)(_r_ip_funcs_p + 0x664));
    llc_ll_pause_enc_rsp_pdu_send(param_1,0);
    uVar4 = 0xb;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
    break;
  case '\x01':
    (**(code **)(_r_ip_funcs_p + 0x3bc))(param_1,0,*(code **)(_r_ip_funcs_p + 0x3bc));
    uVar4 = 0xc;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
    break;
  case '\x02':
    (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,2,*(code **)(_r_ip_funcs_p + 0x664));
    (**(code **)(_r_ip_funcs_p + 0x584))(param_1,*(code **)(_r_ip_funcs_p + 0x584));
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar2,param_1,0xd,*(code **)(_r_ip_funcs_p + 0x684));
    uVar4 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x68c);
    goto _L86;
  case '\x03':
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x4e0))(4,*(code **)(_r_ip_funcs_p + 0x4e0));
    if (iVar3 != 0) {
      llc_ll_enc_rsp_pdu_send(param_1,iVar2 + 0x30,iVar2 + 0x24);
      (**(code **)(_r_ip_funcs_p + 0x580))
                (param_1,*(undefined2 *)(iVar2 + 0x38),iVar2 + 8,*(code **)(_r_ip_funcs_p + 0x580));
      uVar4 = 0xe;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
      goto _L84;
    }
    goto _L68;
  case '\x04':
    if (param_3 == 0) {
      (**(code **)(_r_ip_funcs_p + 0x5a4))
                (param_1,iVar2 + 0x10,iVar2 + 0x28,*(code **)(_r_ip_funcs_p + 0x5a4));
      uVar4 = 0xf;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
      goto _L84;
    }
_L68:
    (**(code **)(_r_ip_funcs_p + 0x5bc))
              (param_1,3,6,*(undefined4 *)(_r_ip_funcs_p + 0x58c),*(code **)(_r_ip_funcs_p + 0x5bc))
    ;
    uVar4 = 0x12;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
_L84:
                    /* WARNING: Could not recover jumptable at 0x000107d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar2,param_1,uVar4,UNRECOVERED_JUMPTABLE);
    return;
  case '\x05':
    (**(code **)(_r_ip_funcs_p + 0x334))
              (param_1,iVar2 + 0x10,iVar2 + 0x20,*(code **)(_r_ip_funcs_p + 0x334));
    (**(code **)(_r_ip_funcs_p + 0x3a0))(param_1,1,*(code **)(_r_ip_funcs_p + 0x3a0));
    llc_ll_start_enc_req_pdu_send(param_1);
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar2,param_1,0x10,*(code **)(_r_ip_funcs_p + 0x684));
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,1,*(code **)(_r_ip_funcs_p + 0x68c));
    uVar5 = *(ushort *)(iVar6 + 0x42) | 0x200;
    goto _L83;
  case '\x06':
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
    (**(code **)(_r_ip_funcs_p + 0x3bc))(param_1,1,*(code **)(_r_ip_funcs_p + 0x3bc));
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar2,param_1,0x11,*(code **)(_r_ip_funcs_p + 0x684));
    (**(code **)(_r_ip_funcs_p + 0x5b4))
              (param_1,&stack0xffffffec,*(undefined4 *)(_r_ip_funcs_p + 0x590),
               *(code **)(_r_ip_funcs_p + 0x5b4));
    return;
  case '\a':
    goto _L54;
  case '\b':
    param_3 = 6;
    goto _L54;
  default:
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
    uVar4 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar2,*(code **)(_r_ip_funcs_p + 0x680));
                    /* WARNING: Could not recover jumptable at 0x00010a02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,uVar4,"llc_encrypt.c",0x473,UNRECOVERED_JUMPTABLE);
    return;
  }
  (*UNRECOVERED_JUMPTABLE)(iVar2,param_1,uVar4,UNRECOVERED_JUMPTABLE);
  uVar4 = 1;
  UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x68c);
_L86:
                    /* WARNING: Could not recover jumptable at 0x0001082a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,1,uVar4,UNRECOVERED_JUMPTABLE);
  return;
_L54:
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    (**(code **)(_r_ip_funcs_p + 0x328))(param_1,1,*(code **)(_r_ip_funcs_p + 0x328));
    (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,0,*(code **)(_r_ip_funcs_p + 0x664));
    if ((param_3 == 0) || (*(char *)(iVar2 + 0x3a) != '\0')) {
      (**(code **)(_r_ip_funcs_p + 0x57c))(param_1,param_3,*(code **)(_r_ip_funcs_p + 0x57c));
    }
    *(ushort *)(iVar6 + 0x42) = *(ushort *)(iVar6 + 0x42) & 0xffdf | (ushort)(param_3 == 0) << 5;
    (**(code **)(_r_ip_funcs_p + 0x610))(param_1,*(code **)(_r_ip_funcs_p + 0x610));
    (**(code **)(_r_ip_funcs_p + 0x688))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x688));
  }
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1,*(code **)(_r_ip_funcs_p + 0x690));
  uVar5 = *(ushort *)(iVar6 + 0x42) & 0xfdff;
_L83:
  *(ushort *)(iVar6 + 0x42) = uVar5;
  return;
}

