/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx_connect_ind_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_pkt_rx_connect_ind_hack(uint param_1)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  void *__src;
  uint extraout_a1;
  uint uVar5;
  undefined1 auStack_34 [12];
  uint uStack_28;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  uVar3 = (uint)bVar1 << 8 | param_1;
  r_ble_log_internal_x1(0x40a00064,uVar3);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  __src = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar4));
  memcpy(auStack_34,__src,0x22);
  r_ble_log_internal_hex(0x20a00065,0x22,auStack_34);
  if ((uStack_28 & 0xffff) == uStack_28 >> 0x10) {
    r_ble_log_internal_x2(0x80a00066,uVar3);
    uVar2 = 0;
  }
  else {
    iVar4 = r_sdk_config_get_opts_ext();
    uVar5 = extraout_a1;
    if ((*(char *)(iVar4 + 0x24) != '\0') &&
       (iVar4 = r_lld_adv_utils_verify_aa(uStack_28), uVar5 = uStack_28, iVar4 == 0)) {
      r_ble_log_internal_x2(0x80a00067,uVar3);
      return 0;
    }
    uVar2 = r_lld_adv_pkt_rx_connect_ind(param_1,uVar5);
  }
  return uVar2;
}

