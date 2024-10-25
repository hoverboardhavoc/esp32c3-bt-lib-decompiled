/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> task.o -> r_btdm_vnd_offload_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_btdm_vnd_offload_process(uint param_1,undefined4 param_2)

{
  if (param_1 < 2) {
                    /* WARNING: Could not emulate address calculation at 0x00010260 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&btdm_ol_task_env)[param_1])(param_2);
    return;
  }
  return;
}

