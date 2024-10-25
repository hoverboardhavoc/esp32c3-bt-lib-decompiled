/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_process_pkt_rx(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&lld_sync_env + param_1 * 4);
  while (iVar2 = (**(code **)(_r_ip_funcs_p + 0x2a4))(param_1,*(code **)(_r_ip_funcs_p + 0x2a4)),
        iVar2 != 0) {
    if (*(ushort *)(iVar3 + 0x52) < 0x673) {
      bVar1 = *(char *)(iVar3 + 99) == '\0';
      (**(code **)(_r_ip_funcs_p + 0x160))(param_1,bVar1,*(code **)(_r_ip_funcs_p + 0x160));
      (**(code **)(_r_ip_funcs_p + 0x164))(param_1,bVar1,*(code **)(_r_ip_funcs_p + 0x164));
    }
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  }
  return;
}

