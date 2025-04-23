/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_cmd_received
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_cmd_received(int param_1,uint param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 uVar7;
  code *UNRECOVERED_JUMPTABLE;
  short asStack_32 [7];
  
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x90))(*(code **)(_r_ip_funcs_p + 0x90));
  if (DAT_0001201d < '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"hci_tl.c",0x5fc,*(code **)(_r_plf_funcs_p + 8));
  }
  if (param_1 != 0xc35) {
    DAT_0001201d = DAT_0001201d + -1;
  }
  if (iVar4 == 0) {
    param_3 = (ushort *)0x0;
    uVar7 = 1;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x30);
    iVar4 = 0;
    goto _L230;
  }
  if (DAT_0001201d < '\0') {
    param_3 = (ushort *)0x0;
    uVar7 = 7;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x30);
    goto _L230;
  }
  switch(*(byte *)(iVar4 + 2) & 0xf) {
  case 0:
  case 2:
    uVar3 = 0;
    break;
  case 1:
  case 3:
    if (param_2 < 2) {
_L196:
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x30);
      if (param_1 == 0x406) {
        uVar1 = *param_3;
        (*UNRECOVERED_JUMPTABLE)(iVar4,0x406,0,param_3);
                    /* WARNING: Could not recover jumptable at 0x00010f9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x56c))
                  ((char)uVar1,0,(char)param_3[1],*(code **)(_r_ip_funcs_p + 0x56c));
        return;
      }
      uVar7 = 2;
_L230:
                    /* WARNING: Could not recover jumptable at 0x00010fbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(iVar4,param_1,uVar7,param_3,UNRECOVERED_JUMPTABLE);
      return;
    }
    uVar3 = (uint)*param_3;
    pbVar6 = (byte *)(**(code **)(_r_plf_funcs_p + 0x20))(*(code **)(_r_plf_funcs_p + 0x20));
    if ((*pbVar6 <= uVar3) || (*(char *)(uVar3 + 0x12040) == '\0')) goto _L196;
    uVar3 = (uVar3 & 0xff) << 8 | 1;
    goto _L197;
  default:
                    /* WARNING: Could not recover jumptable at 0x00010fea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))(param_1,"hci_tl.c",0x68e,*(code **)(_r_plf_funcs_p + 0xc));
    return;
  case 8:
    uVar3 = 2;
    break;
  case 9:
    uVar3 = 3;
  }
  asStack_32[0] = 0;
  uVar2 = 0;
  if (param_2 != 0) {
_L197:
    asStack_32[0] = 0;
    if (*(code **)(iVar4 + 4) == (code *)0x0) {
      uVar2 = 4;
    }
    else {
      if ((*(byte *)(iVar4 + 2) & 0x40) == 0) {
        uVar2 = (**(code **)(_r_modules_funcs_p + 0x18))
                          (0,param_3,asStack_32,param_2,*(code **)(_r_modules_funcs_p + 0x18));
      }
      else {
        uVar2 = (**(code **)(iVar4 + 4))(0,param_3,asStack_32,param_2);
        uVar2 = uVar2 & 0xff;
      }
      if (uVar2 == 1) {
        uVar7 = 0x12;
        UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x30);
        goto _L229;
      }
    }
  }
  iVar5 = (**(code **)(_r_modules_funcs_p + 200))
                    (0x1105,uVar3,param_1,asStack_32[0],*(code **)(_r_modules_funcs_p + 200));
  if (uVar2 != 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar2,param_1,"hci_tl.c",0x6ba,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (iVar5 != 0) {
    if ((asStack_32[0] != 0) && (*(code **)(iVar4 + 4) != (code *)0x0)) {
      if ((*(byte *)(iVar4 + 2) & 0x40) == 0) {
        uVar2 = (**(code **)(_r_modules_funcs_p + 0x18))
                          (iVar5,param_3,asStack_32,param_2,*(code **)(_r_modules_funcs_p + 0x18));
      }
      else {
        uVar2 = (**(code **)(iVar4 + 4))(iVar5,param_3,asStack_32,param_2);
        uVar2 = uVar2 & 0xff;
      }
    }
    if (uVar2 != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (uVar2,param_1,"hci_tl.c",0x6d2,*(code **)(_r_plf_funcs_p + 0xc));
    }
    (**(code **)(_r_modules_funcs_p + 0xe0))(iVar5,*(code **)(_r_modules_funcs_p + 0xe0));
    return;
  }
  uVar7 = 7;
  UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x30);
_L229:
  (*UNRECOVERED_JUMPTABLE)(iVar4,param_1,uVar7,0,UNRECOVERED_JUMPTABLE);
  return;
}

