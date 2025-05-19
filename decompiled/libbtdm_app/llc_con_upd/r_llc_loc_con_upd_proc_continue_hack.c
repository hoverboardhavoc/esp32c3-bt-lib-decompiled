/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_loc_con_upd_proc_continue_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_con_upd_proc_continue_hack(uint param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  code *UNRECOVERED_JUMPTABLE_00;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = param_1 * 4;
  iVar9 = *(int *)(&llc_env + iVar10);
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  if (param_2 == 6) {
    (**(code **)(_r_ip_funcs_p + 0x684))(param_1,6,*(code **)(_r_ip_funcs_p + 0x684));
    (**(code **)(_r_ip_funcs_p + 0x3c8))
              (param_1,*(undefined2 *)(iVar9 + 0xe),*(code **)(_r_ip_funcs_p + 0x3c8));
  }
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar5,*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar6 != param_2) {
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 0x10);
    param_1 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar5,*(code **)(_r_ip_funcs_p + 0x680));
    uVar8 = 0x127;
_L92:
                    /* WARNING: Could not recover jumptable at 0x000106a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,param_2,"llc_con_upd.c",uVar8,UNRECOVERED_JUMPTABLE_00);
    return;
  }
  uVar8 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar5,*(code **)(_r_ip_funcs_p + 0x680));
  switch(uVar8) {
  case 2:
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
    if ((param_3 != 0) &&
       (iVar6 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
       param_1 < *(byte *)(iVar6 + 0xd))) {
      if ((*(int *)(&llc_env + iVar10) != 0) &&
         (((int)(uint)*(byte *)(*(int *)(&llc_env + iVar10) + 0x30) >> 1 & 1U) != 0)) {
        if ((*(ushort *)(iVar9 + 0x42) & 1) == 0) {
          iVar10 = (**(code **)(_r_ip_funcs_p + 0x4f0))(param_1,*(code **)(_r_ip_funcs_p + 0x4f0));
          if (iVar10 == 0) {
            (**(code **)(_r_plf_funcs_p + 8))("llc_con_upd.c",0x13a,*(code **)(_r_plf_funcs_p + 8));
          }
          if (*(int *)(iVar10 + 4) == 0) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"llc_con_upd.c",0x13b,*(code **)(_r_plf_funcs_p + 8));
          }
          *(undefined4 *)(iVar10 + 0x18) = 0;
          *(undefined1 *)(iVar10 + 0x16) = 0;
        }
        goto _L68;
      }
    }
  case 1:
    if ((*(ushort *)(iVar9 + 0x42) & 1) == 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_1,param_3,"llc_con_upd.c",0x149,*(code **)(_r_plf_funcs_p + 0xc));
    }
    *(undefined1 *)(iVar5 + 0x2c) = 1;
  case 0:
    cVar1 = *(char *)(iVar5 + 0x2c);
    *(ushort *)(iVar9 + 0x42) = *(ushort *)(iVar9 + 0x42) | 0x10;
    if (cVar1 != '\0') {
      sVar4 = (**(code **)(_r_ip_funcs_p + 0x338))(param_1);
      sVar2 = *(short *)(*(int *)(&llc_env + iVar10) + 0x10);
      *(undefined1 *)(iVar5 + 0x26) = 1;
      iVar10 = _r_ip_funcs_p;
      *(short *)(iVar5 + 0x24) = sVar4 + sVar2 + 9;
      uVar7 = (**(code **)(iVar10 + 0x7c8))(*(code **)(iVar10 + 0x7c8));
      if (1 < uVar7) {
        *(undefined2 *)(iVar5 + 0x14) = *(undefined2 *)(iVar5 + 0x24);
      }
      (**(code **)(_r_ip_funcs_p + 0x5fc))(param_1,iVar5,*(code **)(_r_ip_funcs_p + 0x5fc));
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x378);
      *(undefined2 *)(iVar5 + 0x22) = *(undefined2 *)(iVar5 + 0x2a);
      param_3 = (*UNRECOVERED_JUMPTABLE_00)
                          (param_1,*(undefined1 *)(iVar5 + 0x26),*(undefined2 *)(iVar5 + 0x28),
                           *(undefined2 *)(iVar5 + 0xc),*(undefined2 *)(iVar5 + 0xe),
                           *(undefined2 *)(iVar5 + 0x24),UNRECOVERED_JUMPTABLE_00);
      (**(code **)(_r_ip_funcs_p + 0x684))(iVar5,param_1,4,*(code **)(_r_ip_funcs_p + 0x684));
      if (param_3 == 0) {
        (**(code **)(_r_ip_funcs_p + 0x5b4))
                  (param_1,&stack0xffffffe4,0,*(code **)(_r_ip_funcs_p + 0x5b4));
        return;
      }
_L68:
      if (*(char *)(iVar5 + 0x2d) == '\0') {
        *(byte *)(iVar9 + 0x45) = *(byte *)(iVar9 + 0x45) & 0x7f;
      }
      (**(code **)(_r_ip_funcs_p + 0x5f0))(param_1,param_3,iVar5,*(code **)(_r_ip_funcs_p + 0x5f0));
      (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0,*(code **)(_r_ip_funcs_p + 0x690));
      *(ushort *)(iVar9 + 0x42) = *(ushort *)(iVar9 + 0x42) & 0xffef;
      return;
    }
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x338))(param_1);
    iVar10 = _r_ip_funcs_p;
    *(undefined2 *)(iVar5 + 0x14) = uVar3;
    (**(code **)(iVar10 + 0x5fc))(param_1,iVar5,*(code **)(iVar10 + 0x5fc));
    *(undefined2 *)(iVar5 + 0x16) = *(undefined2 *)(iVar5 + 0x2a);
    *(undefined4 *)(iVar5 + 0x18) = 0xffffffff;
    *(undefined4 *)(iVar5 + 0x1c) = 0xffffffff;
    *(undefined2 *)(iVar5 + 0x20) = 0xffff;
    llc_ll_connection_param_req_pdu_send(param_1,iVar5);
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x68c));
    if ((*(ushort *)(iVar9 + 0x42) & 1) == 0) {
      (**(code **)(_r_ip_funcs_p + 0x3c8))
                (param_1,*(undefined2 *)(iVar5 + 8),*(code **)(_r_ip_funcs_p + 0x3c8));
      uVar8 = 3;
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x684);
    }
    else {
      uVar8 = 2;
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x684);
    }
    break;
  case 3:
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
    if ((param_3 != 0) ||
       (param_3 = (**(code **)(_r_ip_funcs_p + 0x378))
                            (param_1,*(undefined1 *)(iVar5 + 0x26),*(undefined2 *)(iVar5 + 0x22),
                             *(undefined2 *)(iVar5 + 0x28),*(undefined2 *)(iVar5 + 0xc),
                             *(undefined2 *)(iVar5 + 0xe),*(undefined2 *)(iVar5 + 0x24),
                             *(code **)(_r_ip_funcs_p + 0x378)), param_3 != 0)) goto _L68;
    uVar8 = 4;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x684);
    break;
  case 4:
  case 6:
    goto _L68;
  default:
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 0xc);
    param_2 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar5,*(code **)(_r_ip_funcs_p + 0x680));
    uVar8 = 0x1c0;
    goto _L92;
  }
                    /* WARNING: Could not recover jumptable at 0x0001085a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(iVar5,param_1,uVar8,UNRECOVERED_JUMPTABLE_00);
  return;
}

