/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_trunc_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_trunc_ind(int param_1)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = *(int *)(_lld_scan_env + param_1 * 4);
  r_lld_ext_scan_dynamic_pti_process_eco(iVar1,2);
  pvVar2 = (void *)r_ke_msg_alloc(0x201,0,0xff,0x2c);
  pvVar2 = memcpy(pvVar2,(void *)(iVar1 + 0x58),0x2c);
  *(undefined1 *)((int)pvVar2 + 0x16) = 2;
  *(undefined1 *)((int)pvVar2 + 0x14) = *(undefined1 *)(_lld_scan_env + 0xd);
  r_ke_msg_send();
  return;
}

