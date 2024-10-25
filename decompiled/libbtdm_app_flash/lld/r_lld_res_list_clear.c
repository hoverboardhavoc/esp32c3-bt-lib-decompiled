/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_res_list_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_res_list_clear(void)

{
  ushort uVar1;
  int iVar2;
  undefined1 *__s;
  int iVar3;
  
  __s = &lld_rpa_res_list;
  iVar2 = 0;
  do {
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    uVar1 = *(ushort *)(iVar3 + iVar2);
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    *(ushort *)(iVar3 + iVar2) = uVar1 & 0x7fff;
    iVar2 = iVar2 + 0x34;
    memset(__s,0,0xd);
    __s = __s + 0xd;
  } while (iVar2 != 0x208);
  return;
}

