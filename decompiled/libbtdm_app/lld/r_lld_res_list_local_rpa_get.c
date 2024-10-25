/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> r_lld_res_list_local_rpa_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_res_list_local_rpa_get(void *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  void *__src;
  
  uVar1 = (**(code **)(_r_ip_funcs_p + 0x260))(*(code **)(_r_ip_funcs_p + 0x260));
  if ((uVar1 < 10) &&
     (iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
     (*(ushort *)(iVar3 + uVar1 * 0x34) >> 7 & 1) != 0)) {
    __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                              (uVar1 * 0x34 + 0xc8e & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(param_1,__src,6);
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

