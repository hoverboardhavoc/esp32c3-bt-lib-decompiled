/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  byte bVar3;
  ushort uVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  code *UNRECOVERED_JUMPTABLE;
  int iVar8;
  uint uVar9;
  
  cVar5 = rwip_priority;
  if (param_1 == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar7 = 0xa1c;
_L865:
                    /* WARNING: Could not recover jumptable at 0x0001468c. Too many branches */
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
      uVar7 = 0xa16;
      goto _L865;
    }
    bVar1 = *(byte *)(param_1 + 0x53);
    bVar2 = *(byte *)(param_1 + 0x5d);
    bVar3 = *(byte *)(param_1 + 0x46);
    uVar4 = *(ushort *)(_p_lld_env + 0xd4);
    if ((bVar2 & 0xc0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2b0,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar8 = ((uint)bVar1 * 9 & 0xff) * 0xe;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar8 + 8 + iVar6) =
         (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar2 | (ushort)bVar3 << 8;
    uVar9 = (uint)*(byte *)(param_1 + 0x5c) << 5;
    uVar4 = *(ushort *)(param_1 + 0x46) >> 8;
    if ((uVar9 & 0xffffff1f) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31c,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar4 & 0xffe0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x31d,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar7 = *(undefined4 *)(param_1 + 0x10);
    *(ushort *)(iVar8 + 10 + iVar6) = uVar4 | (ushort)uVar9;
    *(undefined1 *)(param_1 + 0x61) = 0;
    *(undefined4 *)(param_1 + -0x24) = uVar7;
  }
  return;
}

