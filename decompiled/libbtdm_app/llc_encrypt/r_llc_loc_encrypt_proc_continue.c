/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_loc_encrypt_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_encrypt_proc_continue(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  code *pcVar9;
  int iVar10;
  
  iVar10 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x7e0))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x7e0));
  if (iVar3 != 0) {
    return;
  }
  if (iVar2 != param_2) {
    if (param_2 == 9) {
      if (param_3 != 0x13) {
        if (param_3 < 0x14) {
          if (param_3 == 6) {
            if (iVar2 != 5) goto _L25;
          }
          else {
            uVar8 = 8;
_L46:
            if (param_3 != uVar8) goto _L21;
          }
        }
        else {
          if (param_3 != 0x1a) {
            uVar8 = 0x22;
            goto _L46;
          }
_L25:
          if (iVar2 != 4) goto _L21;
        }
      }
    }
    else {
_L21:
      param_3 = 0x3d;
      (**(code **)(_r_ip_funcs_p + 0x55c))(param_1,0x3d,1,*(code **)(_r_ip_funcs_p + 0x55c));
    }
_L22:
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    iVar2 = _r_ip_funcs_p;
    if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
       ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
      *(byte *)(iVar10 + 0x45) = *(byte *)(iVar10 + 0x45) & 0xf7;
      (**(code **)(iVar2 + 0x328))(param_1,1,*(code **)(iVar2 + 0x328));
      (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,0,*(code **)(_r_ip_funcs_p + 0x664));
      (**(code **)(_r_ip_funcs_p + 0x688))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x688));
      *(ushort *)(iVar10 + 0x42) = (ushort)(param_3 == 0) << 5 | *(ushort *)(iVar10 + 0x42) & 0xffdf
      ;
      (**(code **)(_r_ip_funcs_p + 0x610))(param_1,*(code **)(_r_ip_funcs_p + 0x610));
    }
    (**(code **)(_r_ip_funcs_p + 0x57c))
              (param_1,param_3,*(undefined1 *)(iVar1 + 0x3a),*(code **)(_r_ip_funcs_p + 0x57c));
    (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0,*(code **)(_r_ip_funcs_p + 0x690));
    uVar7 = *(ushort *)(iVar10 + 0x42) & 0xfdff;
_L47:
    *(ushort *)(iVar10 + 0x42) = uVar7;
    goto _L40;
  }
  switch(param_2) {
  case 0:
    (**(code **)(_r_ip_funcs_p + 0x328))(param_1,0,*(code **)(_r_ip_funcs_p + 0x328));
    if (*(char *)(iVar1 + 0x3a) == '\0') goto _L34;
    llc_ll_pause_enc_req_pdu_send(param_1);
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar1,param_1,1,*(code **)(_r_ip_funcs_p + 0x684));
    uVar5 = 1;
    pcVar9 = *(code **)(_r_ip_funcs_p + 0x664);
_L39:
    uVar4 = 1;
    uVar6 = uVar5;
    break;
  case 1:
    (**(code **)(_r_ip_funcs_p + 0x664))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x664));
    (**(code **)(_r_ip_funcs_p + 0x688))(param_1,1,*(code **)(_r_ip_funcs_p + 0x688));
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
    (**(code **)(_r_ip_funcs_p + 0x3a0))(param_1,0,*(code **)(_r_ip_funcs_p + 0x3a0));
    (**(code **)(_r_ip_funcs_p + 0x3bc))(param_1,0,*(code **)(_r_ip_funcs_p + 0x3bc));
    llc_ll_pause_enc_rsp_pdu_send(param_1,*(undefined4 *)(_r_ip_funcs_p + 0x588));
    uVar6 = 2;
    pcVar9 = *(code **)(_r_ip_funcs_p + 0x684);
    goto _L50;
  case 2:
_L34:
    (**(code **)(_r_ip_funcs_p + 0x584))(param_1,*(code **)(_r_ip_funcs_p + 0x584));
    uVar6 = 3;
    pcVar9 = *(code **)(_r_ip_funcs_p + 0x684);
_L50:
    (*pcVar9)(iVar1,param_1,uVar6,pcVar9);
    goto _L40;
  case 3:
    llc_ll_enc_req_pdu_send
              (param_1,*(undefined2 *)(iVar1 + 0x38),iVar1 + 8,iVar1 + 0x28,iVar1 + 0x20);
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar1,param_1,4,*(code **)(_r_ip_funcs_p + 0x684));
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x68c));
    uVar5 = 2;
    pcVar9 = *(code **)(_r_ip_funcs_p + 0x664);
    uVar4 = 2;
    uVar6 = 2;
    if (*(char *)(iVar1 + 0x3a) == '\0') goto _L39;
    break;
  case 4:
    (**(code **)(_r_ip_funcs_p + 0x664))(param_1,0,2,*(code **)(_r_ip_funcs_p + 0x664));
    (**(code **)(_r_ip_funcs_p + 0x688))(param_1,1,*(code **)(_r_ip_funcs_p + 0x688));
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar1,param_1,5,*(code **)(_r_ip_funcs_p + 0x684));
    uVar6 = 1;
    pcVar9 = *(code **)(_r_ip_funcs_p + 0x68c);
    goto _L49;
  case 5:
    (**(code **)(_r_ip_funcs_p + 0x5a4))
              (param_1,iVar1 + 0x10,iVar1 + 0x28,*(code **)(_r_ip_funcs_p + 0x5a4));
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar1,param_1,6,*(code **)(_r_ip_funcs_p + 0x684));
    uVar6 = 0;
    pcVar9 = *(code **)(_r_ip_funcs_p + 0x68c);
_L49:
    uVar4 = 0;
    break;
  case 6:
    (**(code **)(_r_ip_funcs_p + 0x334))
              (param_1,iVar1 + 0x10,iVar1 + 0x20,*(code **)(_r_ip_funcs_p + 0x334));
    (**(code **)(_r_ip_funcs_p + 0x3a0))(param_1,1,*(code **)(_r_ip_funcs_p + 0x3a0));
    (**(code **)(_r_ip_funcs_p + 0x3bc))(param_1,1,*(code **)(_r_ip_funcs_p + 0x3bc));
    llc_ll_start_enc_rsp_pdu_send(param_1,0);
    (**(code **)(_r_ip_funcs_p + 0x684))(iVar1,param_1,8,*(code **)(_r_ip_funcs_p + 0x684));
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x68c));
    uVar7 = *(ushort *)(iVar10 + 0x42) | 0x200;
    goto _L47;
  default:
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_1,param_2,"llc_encrypt.c",0x2ac,*(code **)(_r_plf_funcs_p + 0xc));
    param_3 = 0x1f;
    goto _L40;
  case 8:
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
    goto _L22;
  }
  (*pcVar9)(param_1,uVar4,uVar6,pcVar9);
_L40:
                    /* WARNING: Could not recover jumptable at 0x00010436. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x7e0))(0,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x7e0));
  return;
}

