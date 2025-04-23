/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_rem_encrypt_proc_continue_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_encrypt_proc_continue_eco(uint param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  ushort uVar6;
  code *UNRECOVERED_JUMPTABLE;
  int iVar7;
  
  iVar7 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  puVar4 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar3,*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar5 == param_2) {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar3,*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar5 == 0x10) {
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
      (**(code **)(_r_ip_funcs_p + 0x3bc))(param_1,1,*(code **)(_r_ip_funcs_p + 0x3bc));
      llc_ll_start_enc_rsp_pdu_send(param_1,0);
      *puVar4 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar4;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((param_1 < *(byte *)(iVar5 + 0xd)) &&
          (iVar5 = *(int *)(&llc_env + param_1 * 4), iVar5 != 0)) &&
         ((*(byte *)(iVar5 + 0x44) & 3) != 3)) {
        (**(code **)(_r_ip_funcs_p + 0x328))(param_1,1,*(code **)(_r_ip_funcs_p + 0x328));
        (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,0,*(code **)(_r_ip_funcs_p + 0x664));
        if ((param_3 == 0) || (*(char *)(iVar3 + 0x3a) != '\0')) {
          (**(code **)(_r_ip_funcs_p + 0x57c))(param_1,param_3,*(code **)(_r_ip_funcs_p + 0x57c));
        }
        iVar3 = _r_ip_funcs_p;
        *(ushort *)(iVar7 + 0x42) = (ushort)(param_3 == 0) << 5 | *(ushort *)(iVar7 + 0x42) & 0xffdf
        ;
        (**(code **)(iVar3 + 0x610))(param_1,*(code **)(iVar3 + 0x610));
        (**(code **)(_r_ip_funcs_p + 0x688))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x688));
      }
      (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1,*(code **)(_r_ip_funcs_p + 0x690));
      *(ushort *)(iVar7 + 0x42) = *(ushort *)(iVar7 + 0x42) & 0xfdff;
      return;
    }
    if (iVar5 == 0x12) goto _L92;
  }
  else {
_L92:
    *puVar4 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar4;
  }
  iVar7 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar5 != param_2) {
    if ((param_2 != 0x13) || (param_3 == 0x3d)) {
      param_3 = 0x3d;
      (**(code **)(_r_ip_funcs_p + 0x55c))(param_1,0x3d,1,*(code **)(_r_ip_funcs_p + 0x55c));
    }
    goto _L55;
  }
  cVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar3,*(code **)(_r_ip_funcs_p + 0x680));
  switch(cVar1 + -10) {
  case '\0':
    (**(code **)(_r_ip_funcs_p + 0x328))(param_1,0,*(code **)(_r_ip_funcs_p + 0x328));
    (**(code **)(_r_ip_funcs_p + 0x688))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x688));
    if ((uint)*(byte *)(iVar3 + 0x3a) != ((int)(uint)*(ushort *)(iVar7 + 0x42) >> 5 & 1U)) {
      (**(code **)(_r_ip_funcs_p + 0x5bc))
                (param_1,3,0x24,*(undefined4 *)(_r_ip_funcs_p + 0x58c),
                 *(code **)(_r_ip_funcs_p + 0x5bc));
      (**(code **)(_r_ip_funcs_p + 0x684))(iVar3,param_1,0x12,*(code **)(_r_ip_funcs_p + 0x684));
    }
    if (*(char *)(iVar3 + 0x3a) == '\0') {
      (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,*(code **)(_r_ip_funcs_p + 0x664));
      (**(code **)(_r_ip_funcs_p + 0x584))(param_1,*(code **)(_r_ip_funcs_p + 0x584));
      uVar2 = 0xd;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
      goto _L85;
    }
    (**(code **)(_r_ip_funcs_p + 0x3a0))(param_1,0,*(code **)(_r_ip_funcs_p + 0x3a0));
    (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,1,*(code **)(_r_ip_funcs_p + 0x664));
    llc_ll_pause_enc_rsp_pdu_send(param_1,0);
    uVar2 = 0xb;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
    break;
  case '\x01':
    (**(code **)(_r_ip_funcs_p + 0x3bc))(param_1,0,*(code **)(_r_ip_funcs_p + 0x3bc));
    uVar2 = 0xc;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
    break;
  case '\x02':
    (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,*(code **)(_r_ip_funcs_p + 0x664));
    (**(code **)(_r_ip_funcs_p + 0x584))(param_1,*(code **)(_r_ip_funcs_p + 0x584));
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar3,param_1,0xd,*(code **)(_r_ip_funcs_p + 0x684));
    uVar2 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x68c);
    goto _L87;
  case '\x03':
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x4e0))(4,*(code **)(_r_ip_funcs_p + 0x4e0));
    if (iVar5 != 0) {
      llc_ll_enc_rsp_pdu_send(param_1,iVar3 + 0x30,iVar3 + 0x24);
      (**(code **)(_r_ip_funcs_p + 0x580))
                (param_1,*(undefined2 *)(iVar3 + 0x38),iVar3 + 8,*(code **)(_r_ip_funcs_p + 0x580));
      uVar2 = 0xe;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
      goto _L85;
    }
    goto _L68;
  case '\x04':
    if (param_3 == 0) {
      (**(code **)(_r_ip_funcs_p + 0x5a4))
                (param_1,iVar3 + 0x10,iVar3 + 0x28,*(code **)(_r_ip_funcs_p + 0x5a4));
      uVar2 = 0xf;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
      goto _L85;
    }
_L68:
    (**(code **)(_r_ip_funcs_p + 0x5bc))
              (param_1,3,6,*(undefined4 *)(_r_ip_funcs_p + 0x58c),*(code **)(_r_ip_funcs_p + 0x5bc))
    ;
    uVar2 = 0x12;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x684);
_L85:
                    /* WARNING: Could not recover jumptable at 0x000107c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar3,param_1,uVar2,UNRECOVERED_JUMPTABLE);
    return;
  case '\x05':
    (**(code **)(_r_ip_funcs_p + 0x334))
              (param_1,iVar3 + 0x10,iVar3 + 0x20,*(code **)(_r_ip_funcs_p + 0x334));
    (**(code **)(_r_ip_funcs_p + 0x3a0))(param_1,1,*(code **)(_r_ip_funcs_p + 0x3a0));
    llc_ll_start_enc_req_pdu_send(param_1);
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar3,param_1,0x10,*(code **)(_r_ip_funcs_p + 0x684));
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,*(code **)(_r_ip_funcs_p + 0x68c));
    uVar6 = *(ushort *)(iVar7 + 0x42) | 0x200;
    goto _L84;
  case '\x06':
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
    (**(code **)(_r_ip_funcs_p + 0x3bc))(param_1,1,*(code **)(_r_ip_funcs_p + 0x3bc));
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar3,param_1,0x11,*(code **)(_r_ip_funcs_p + 0x684));
    (**(code **)(_r_ip_funcs_p + 0x5b4))
              (param_1,&stack0xffffffec,*(undefined4 *)(_r_ip_funcs_p + 0x590),
               *(code **)(_r_ip_funcs_p + 0x5b4));
    return;
  case '\a':
    goto _L55;
  case '\b':
    param_3 = 6;
    goto _L55;
  default:
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar3,*(code **)(_r_ip_funcs_p + 0x680));
                    /* WARNING: Could not recover jumptable at 0x000109f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,uVar2,"llc_encrypt.c",0x473,UNRECOVERED_JUMPTABLE);
    return;
  }
  (*UNRECOVERED_JUMPTABLE)(iVar3,param_1,uVar2,UNRECOVERED_JUMPTABLE);
  uVar2 = 1;
  UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x68c);
_L87:
                    /* WARNING: Could not recover jumptable at 0x0001081e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,1,uVar2,UNRECOVERED_JUMPTABLE);
  return;
_L55:
  iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((param_1 < *(byte *)(iVar5 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    (**(code **)(_r_ip_funcs_p + 0x328))(param_1,1,*(code **)(_r_ip_funcs_p + 0x328));
    (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,0,*(code **)(_r_ip_funcs_p + 0x664));
    if ((param_3 == 0) || (*(char *)(iVar3 + 0x3a) != '\0')) {
      (**(code **)(_r_ip_funcs_p + 0x57c))(param_1,param_3,*(code **)(_r_ip_funcs_p + 0x57c));
    }
    iVar3 = _r_ip_funcs_p;
    *(ushort *)(iVar7 + 0x42) = (ushort)(param_3 == 0) << 5 | *(ushort *)(iVar7 + 0x42) & 0xffdf;
    (**(code **)(iVar3 + 0x610))(param_1,*(code **)(iVar3 + 0x610));
    (**(code **)(_r_ip_funcs_p + 0x688))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x688));
  }
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1,*(code **)(_r_ip_funcs_p + 0x690));
  uVar6 = *(ushort *)(iVar7 + 0x42) & 0xfdff;
_L84:
  *(ushort *)(iVar7 + 0x42) = uVar6;
  return;
}

