/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_trunc_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_trunc_ind(uint param_1)

{
  int iVar1;
  void *__dest;
  
  iVar1 = *(int *)(_lld_scan_env + param_1 * 4);
  r_lld_ext_scan_dynamic_pti_process_eco(iVar1,2);
  __dest = (void *)r_ke_msg_alloc(0x201,0,0xff,0x2c);
  memcpy(__dest,(void *)(iVar1 + 0x58),0x2c);
  *(undefined1 *)((int)__dest + 0x16) = 2;
  *(undefined1 *)((int)__dest + 0x14) = *(undefined1 *)(_lld_scan_env + 0xd);
  r_ke_msg_send(__dest);
  r_ble_log_internal_x2
            (0x40a10148,(uint)CONCAT12(*(undefined1 *)(iVar1 + 0x41),*(undefined2 *)(iVar1 + 0x36)),
             (uint)*(byte *)(iVar1 + 0x3e) << 8 | (uint)*(byte *)(iVar1 + 0x3d) << 0x10 | param_1);
  return;
}

