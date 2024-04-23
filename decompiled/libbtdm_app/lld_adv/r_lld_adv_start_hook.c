/*
 * Last changed at upstream commit 9780fd66d97866977d972fb63319830f47f12785
 * https://github.com/espressif/esp32c3-bt-lib/commit/9780fd66d97866977d972fb63319830f47f12785
 * Upstream date: 2024-04-23 11:19:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a771b7c)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_start_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_start_hook(int param_1,int param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  
  if (param_1 == 0) {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
    sVar1 = *(short *)(iVar5 + 0x10);
    if (((sVar1 != 0) && (*(short *)(iVar5 + 0x12) != 0)) &&
       (*(int *)(&lld_adv_env + param_2 * 4) != 0)) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar8 = _r_plf_funcs_p;
      *(short *)(iVar6 + param_2 * 0x5a + 0xc) = sVar1;
      uVar2 = *(undefined2 *)(iVar5 + 0x12);
      iVar5 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
      *(undefined2 *)(param_2 * 0x5a + 0xe + iVar5) = uVar2;
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if ((*(char *)(iVar5 + 0x18) == '\0') && ((*(ushort *)(param_3 + 0x18) & 0x10) != 0)) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = param_2 * 9 & 0xff;
      iVar8 = uVar4 * 0xe + 2;
      uVar3 = *(ushort *)(iVar5 + iVar8);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar5 + iVar8) = uVar3 & 0xffdf;
      iVar8 = (*pcVar7)(0x1400,pcVar7);
      iVar5 = (uVar4 + 1 & 0xff) * 0xe + 2;
      uVar3 = *(ushort *)(iVar8 + iVar5);
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar8 + iVar5) = uVar3 & 0xffdf;
    }
    lld_rpa_renew_start(*(undefined1 *)(param_3 + 0x1e));
  }
  else {
    llm_ext_adv_get_own_addr(param_2,*(undefined1 *)(param_3 + 0x1e),param_3);
  }
  return 0;
}

