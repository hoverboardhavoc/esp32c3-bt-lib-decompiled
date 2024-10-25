/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> r_dl_upd_proc_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_dl_upd_proc_start(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  if (*(short *)(iVar2 + 0x20) == *(short *)(iVar2 + 0x14)) {
    if (*(short *)(iVar2 + 0x22) == *(short *)(iVar2 + 0x18)) {
      return;
    }
  }
  puVar3 = (undefined4 *)r_ke_msg_alloc(0x10a,param_1 << 8 | 1,0x14);
  *(undefined1 *)(puVar3 + 1) = 7;
  r_llc_proc_state_set(param_1,0);
  *puVar3 = r_llc_dle_proc_err_cb;
  *(undefined2 *)(puVar3 + 2) = *(undefined2 *)(iVar2 + 0x20);
  uVar1 = *(undefined2 *)(iVar2 + 0x22);
  *(undefined1 *)(puVar3 + 4) = 0;
  *(undefined2 *)((int)puVar3 + 10) = uVar1;
  puVar3[3] = 0x429000fb;
  r_ke_msg_send(puVar3);
  return;
}

