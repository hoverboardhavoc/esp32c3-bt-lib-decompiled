/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_rx_enc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_rx_enc(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar4 != 0) {
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    iVar2 = param_1 * 0x5a + 2;
    uVar1 = *(ushort *)(iVar3 + iVar2);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar3 + iVar2) = uVar1 & 0xfeff | (ushort)(param_2 << 8);
    *(ushort *)(iVar4 + 0x84) = *(ushort *)(iVar4 + 0x84) & 0xffdf | (ushort)(param_2 << 5);
  }
  return;
}

