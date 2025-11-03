/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_cleanup(int param_1,byte param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  
  piVar1 = (int *)(&lld_sync_env + param_1 * 4);
  if (*piVar1 != 0) {
    r_ble_log_internal_x1
              (0x400500cb,
               (uint)*(ushort *)(*piVar1 + 0x4a) | param_1 << 0x10 | (uint)param_2 << 0x18);
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
    *puVar2 = (char)param_1;
    puVar2[1] = param_2;
    r_ke_msg_send();
    r_ke_free(*piVar1);
    *piVar1 = 0;
  }
  return;
}

