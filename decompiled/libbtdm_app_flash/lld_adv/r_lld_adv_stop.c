/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_adv_stop(uint param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar4 != 0) {
    r_ble_log_internal_x1(0x4000006e,(uint)*(byte *)(iVar4 + 0x89) << 8 | param_1);
    if (*(char *)(iVar4 + 0x89) == '\0') {
      r_lld_adv_end_hack(param_1,1,0);
      uVar2 = 0;
    }
    else {
      if (*(char *)(iVar4 + 0x89) == '\x01') {
        bVar1 = *(byte *)(iVar4 + 0x87);
        iVar3 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar3) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfdffffff | 0x2000000;
        *(undefined1 *)(iVar4 + 0x89) = 2;
      }
      uVar2 = 0;
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

