/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_aux_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_aux_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  code *UNRECOVERED_JUMPTABLE;
  int iVar8;
  
  cVar5 = rwip_priority;
  if (param_1 == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar7 = 0x9de;
_L793:
                    /* WARNING: Could not recover jumptable at 0x00014556. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(0,"lld_adv.c",uVar7,UNRECOVERED_JUMPTABLE);
    return;
  }
  if ((uint)(*(int *)(param_1 + 0x30) << 1) <=
      (*(int *)(param_1 + 4) - *(int *)(param_1 + 0x2c) & 0xfffffffU)) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 4);
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar5;
  }
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x6b0))(param_1,*(code **)(_r_ip_funcs_p + 0x6b0));
  if (iVar6 != 0) {
    if (*(int *)(param_1 + 0x24) == -1) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
      uVar7 = 0x9d8;
      goto _L793;
    }
    bVar1 = *(byte *)(param_1 + 0x53);
    bVar2 = *(byte *)(param_1 + 0x5d);
    sVar3 = *(short *)(param_1 + 0x46);
    uVar4 = *(ushort *)(_p_lld_env + 0xd4);
    if (0x3f < bVar2) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2b0,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar8 = ((uint)bVar1 * 9 & 0xff) * 0xe;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar8 + 8 + iVar6) = (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar2 | sVar3 << 8;
    bVar1 = *(byte *)(param_1 + 0x5c);
    uVar4 = *(ushort *)(param_1 + 0x46) >> 8;
    if ((bVar1 & 0xf8) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31c,*(code **)(_r_plf_funcs_p + 8));
    }
    if (0x1f < uVar4) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31d,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar7 = *(undefined4 *)(param_1 + 0x10);
    *(ushort *)(iVar8 + 10 + iVar6) = uVar4 | (ushort)bVar1 << 5;
    *(undefined1 *)(param_1 + 0x61) = 0;
    *(undefined4 *)(param_1 + -0x24) = uVar7;
  }
  return;
}

