/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_phys_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_phys_update(int param_1,int param_2,undefined1 param_3,undefined2 param_4)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar4 != 0) {
    if (*(char *)(iVar4 + 0x46) == '\0') {
      *(undefined1 *)(iVar4 + 0x46) = 3;
      *(undefined1 *)(iVar4 + 0x35) = param_3;
      *(undefined2 *)(iVar4 + 0x44) = param_4;
      uVar1 = *(ushort *)(&byte_tx_time + param_2 * 2);
      uVar2 = *(ushort *)(&byte_tx_time + (uint)*(byte *)(iVar4 + 0x94) * 2);
      *(char *)(iVar4 + 0x34) = (char)param_2;
      uVar3 = 0;
      if (uVar2 < uVar1) {
        r_lld_con_tx_len_update(*(undefined4 *)(iVar4 + 100));
      }
      goto _L783;
    }
    r_assert_param(*(char *)(iVar4 + 0x46),0,"lld_con.c",0xf5e);
  }
  uVar3 = 0xc;
_L783:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

