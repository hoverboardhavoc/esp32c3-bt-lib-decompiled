/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_res_list_local_rpa_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_res_list_local_rpa_get(void *param_1)

{
  uint uVar1;
  int iVar2;
  void *__src;
  
  uVar1 = r_lld_ral_search();
  if ((uVar1 < 10) &&
     (iVar2 = r_emi_get_mem_addr_by_offset(0xc60), (*(ushort *)(iVar2 + uVar1 * 0x34) >> 7 & 1) != 0
     )) {
    __src = (void *)r_emi_get_mem_addr_by_offset(uVar1 * 0x34 + 0xc8e & 0xffff);
    memcpy(param_1,__src,6);
    return 0;
  }
  return 2;
}

