/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
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
  char cVar8;
  int iVar9;
  char cVar10;
  
  if (param_1 == 0) {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
    sVar1 = *(short *)(iVar5 + 0x10);
    if (((sVar1 != 0) && (*(short *)(iVar5 + 0x12) != 0)) &&
       (*(int *)(&lld_adv_env + param_2 * 4) != 0)) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar9 = _r_plf_funcs_p;
      *(short *)(iVar6 + param_2 * 0x5a + 0xc) = sVar1;
      uVar2 = *(undefined2 *)(iVar5 + 0x12);
      iVar5 = (**(code **)(iVar9 + 0xbc))(0x400,*(code **)(iVar9 + 0xbc));
      *(undefined2 *)(param_2 * 0x5a + 0xe + iVar5) = uVar2;
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if ((*(char *)(iVar5 + 0x18) == '\0') && ((*(ushort *)(param_3 + 0x18) & 0x10) != 0)) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = param_2 * 9 & 0xff;
      iVar9 = uVar4 * 0xe + 2;
      uVar3 = *(ushort *)(iVar5 + iVar9);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar5 + iVar9) = uVar3 & 0xffdf;
      iVar9 = (*pcVar7)(0x1400,pcVar7);
      iVar5 = (uVar4 + 1 & 0xff) * 0xe + 2;
      uVar3 = *(ushort *)(iVar9 + iVar5);
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar9 + iVar5) = uVar3 & 0xffdf;
    }
    iVar5 = *(int *)(&lld_adv_env + param_2 * 4);
    iVar9 = llm_csa_get();
    cVar8 = '\x02';
    if ((*(ushort *)(iVar5 + 0x74) & 0x10) == 0) {
      cVar8 = *(char *)(iVar5 + 0x92);
    }
    if (iVar9 != 0) {
      param_2 = param_2 * 0x7e;
      for (cVar10 = '\0'; cVar10 != cVar8; cVar10 = cVar10 + '\x01') {
        if ((iVar9 - 1U & 0xfe) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x162,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar5 + param_2 + 2);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + param_2 + 2) =
             uVar3 & 0xffdf | (ushort)(((iVar9 - 1U & 0xff) << 0x15) >> 0x10);
        param_2 = param_2 + 0xe;
      }
    }
    lld_rpa_renew_start(*(undefined1 *)(param_3 + 0x1e));
  }
  else {
    llm_ext_adv_get_own_addr(param_2,*(undefined1 *)(param_3 + 0x1e),param_3);
  }
  return 0;
}

