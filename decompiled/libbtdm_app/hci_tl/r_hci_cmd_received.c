/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 uVar7;
  code *UNRECOVERED_JUMPTABLE;
  short asStack_32 [7];
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x90))(*(code **)(_r_ip_funcs_p + 0x90));
  if (DAT_0001201d < '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"hci_tl.c",0x5fc,*(code **)(_r_plf_funcs_p + 8));
  }
  if (param_1 != 0xc35) {
    DAT_0001201d = DAT_0001201d + -1;
  }
  if (iVar3 == 0) {
    param_3 = (ushort *)0x0;
    uVar7 = 1;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x30);
    iVar3 = 0;
    goto _L221;
  }
  if (DAT_0001201d < '\0') {
    param_3 = (ushort *)0x0;
    uVar7 = 7;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x30);
    goto _L221;
  }
  switch(*(byte *)(iVar3 + 2) & 0xf) {
  case 0:
  case 2:
    uVar2 = 0;
    break;
  case 1:
  case 3:
    if (1 < param_2) {
      uVar2 = (uint)*param_3;
      pbVar5 = (byte *)(**(code **)(_r_plf_funcs_p + 0x20))(*(code **)(_r_plf_funcs_p + 0x20));
      if ((uVar2 < *pbVar5) && (*(char *)(uVar2 + 0x12040) != '\0')) {
        uVar2 = (uVar2 & 0xff) << 8 | 1;
        break;
      }
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x30);
    if (param_1 == 0x406) {
      uVar1 = *param_3;
      (*UNRECOVERED_JUMPTABLE)(iVar3,0x406,0,param_3);
                    /* WARNING: Could not recover jumptable at 0x00010f2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x56c))
                ((char)uVar1,0,(char)param_3[1],*(code **)(_r_ip_funcs_p + 0x56c));
      return;
    }
    uVar7 = 2;
_L221:
                    /* WARNING: Could not recover jumptable at 0x00010f4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar3,param_1,uVar7,param_3,UNRECOVERED_JUMPTABLE);
    return;
  default:
                    /* WARNING: Could not recover jumptable at 0x00010f78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))(param_1,"hci_tl.c",0x68e,*(code **)(_r_plf_funcs_p + 0xc));
    return;
  case 8:
    uVar2 = 2;
    break;
  case 9:
    uVar2 = 3;
  }
  asStack_32[0] = 0;
  if (param_2 == 0) {
    uVar4 = 0;
  }
  else if (*(code **)(iVar3 + 4) == (code *)0x0) {
    uVar4 = 4;
  }
  else {
    if ((*(byte *)(iVar3 + 2) & 0x40) == 0) {
      uVar4 = (**(code **)(_r_modules_funcs_p + 0x18))
                        (0,param_3,asStack_32,*(code **)(_r_modules_funcs_p + 0x18));
    }
    else {
      uVar4 = (**(code **)(iVar3 + 4))(0,param_3,asStack_32,param_2 & 0xffff);
      uVar4 = uVar4 & 0xff;
    }
    if (uVar4 == 1) {
      uVar7 = 0x12;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x30);
      goto _L220;
    }
  }
  iVar6 = (**(code **)(_r_modules_funcs_p + 200))
                    (0x1105,uVar2,param_1,asStack_32[0],*(code **)(_r_modules_funcs_p + 200));
  if (uVar4 != 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar4,param_1,"hci_tl.c",0x6ba,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (iVar6 != 0) {
    if ((asStack_32[0] != 0) && (*(code **)(iVar3 + 4) != (code *)0x0)) {
      if ((*(byte *)(iVar3 + 2) & 0x40) == 0) {
        uVar4 = (**(code **)(_r_modules_funcs_p + 0x18))
                          (iVar6,param_3,asStack_32,*(code **)(_r_modules_funcs_p + 0x18));
      }
      else {
        uVar4 = (**(code **)(iVar3 + 4))(iVar6,param_3,asStack_32,param_2 & 0xffff);
        uVar4 = uVar4 & 0xff;
      }
    }
    if (uVar4 != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (uVar4,param_1,"hci_tl.c",0x6d2,*(code **)(_r_plf_funcs_p + 0xc));
    }
    (**(code **)(_r_modules_funcs_p + 0xe0))(iVar6,*(code **)(_r_modules_funcs_p + 0xe0));
    return;
  }
  uVar7 = 7;
  UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x30);
_L220:
  (*UNRECOVERED_JUMPTABLE)(iVar3,param_1,uVar7,0,UNRECOVERED_JUMPTABLE);
  return;
}

