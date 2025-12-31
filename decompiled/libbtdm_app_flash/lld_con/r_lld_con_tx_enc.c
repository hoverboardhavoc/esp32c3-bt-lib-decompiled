/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_enc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_tx_enc(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar4 != 0) {
    r_ble_log_internal_x1
              (0x40e300f6,(uint)*(ushort *)(iVar4 + 0x7c) | param_1 << 0x10 | param_2 << 0x18);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    iVar2 = param_1 * 0x5a + 2;
    uVar1 = *(ushort *)(iVar3 + iVar2);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar3 + iVar2) = uVar1 & 0xfdff | (ushort)(param_2 << 9);
    *(ushort *)(iVar4 + 0x84) = *(ushort *)(iVar4 + 0x84) & 0xffbf | (ushort)(param_2 << 6);
  }
  return;
}

