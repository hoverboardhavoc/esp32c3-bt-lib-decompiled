/*
 * Last changed at upstream commit a075a8fde411bdd92973051edf2cd234601b259c
 * https://github.com/espressif/esp32c3-bt-lib/commit/a075a8fde411bdd92973051edf2cd234601b259c
 * Upstream date: 2023-11-30 21:15:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(70ab55f)
 * Source: libbtdm_app -> lld.o -> r_lld_res_list_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_res_list_rem(void *param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  void *__src;
  undefined4 uVar7;
  
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x260))(*(code **)(_r_ip_funcs_p + 0x260));
  if (uVar3 < 10) {
    iVar2 = uVar3 * 0x34;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if (((int)((uint)*(ushort *)(iVar4 + iVar2) << 0x12) < 0) &&
       (uVar5 = lld_wl_search(param_1,param_2), uVar5 < 0xc)) {
      if ((&lld_wl_res_list)[uVar5] == 0) {
        iVar4 = (**(code **)(_r_osi_funcs_p + 0x74))(0x17,*(code **)(_r_osi_funcs_p + 0x74));
        (&lld_wl_res_list)[uVar5] = iVar4;
      }
      puVar6 = (undefined1 *)(&lld_wl_res_list)[uVar5];
      if (puVar6 != (undefined1 *)0x0) {
        *puVar6 = (char)param_2;
        memcpy(puVar6 + 1,param_1,6);
        iVar4 = (&lld_wl_res_list)[uVar5];
        __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                  (uVar3 * 0x34 + 0xc62 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy((void *)(iVar4 + 7),__src,0x10);
      }
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar4 + iVar2);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar2) = uVar1 & 0x7fff;
    memset(&lld_rpa_res_list + uVar3 * 0xd,0,0xd);
    uVar7 = 0;
  }
  else {
    uVar7 = 2;
  }
  return uVar7;
}

