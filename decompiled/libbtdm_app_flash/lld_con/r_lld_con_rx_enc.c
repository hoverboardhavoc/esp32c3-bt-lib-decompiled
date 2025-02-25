/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_rx_enc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_rx_enc(uint param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar4 != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar2 + 0x28) & 0x20) != 0) {
      iVar2 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar2 + 0x2c) < 3) {
        r_ble_log_internal_x1
                  (0x40e30022,param_1 | param_2 << 8 | (uint)*(ushort *)(iVar4 + 0x7c) << 0x10);
      }
    }
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    iVar2 = param_1 * 0x5a + 2;
    uVar1 = *(ushort *)(iVar3 + iVar2);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar2 + iVar3) = uVar1 & 0xfeff | (ushort)(param_2 << 8);
    *(ushort *)(iVar4 + 0x84) = *(ushort *)(iVar4 + 0x84) & 0xffdf | (ushort)(param_2 << 5);
  }
  return;
}

