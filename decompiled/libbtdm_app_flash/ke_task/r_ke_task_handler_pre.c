/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ke_task.o -> r_ke_task_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_ke_task_handler_pre(int param_1)

{
  if (*(short *)(param_1 + 4) == 0x209) {
    lld_init_end_ind_pre_handler
              (0x209,param_1 + 0xc,*(undefined2 *)(param_1 + 6),*(undefined2 *)(param_1 + 8));
    return;
  }
  return;
}

