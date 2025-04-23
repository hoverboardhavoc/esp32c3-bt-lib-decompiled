/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> nvds.o -> r_nvds_purge
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_nvds_purge(uint param_1,void *param_2)

{
  int iVar1;
  void *__dest;
  uint uVar2;
  int iVar3;
  undefined1 uStack_28;
  byte bStack_27;
  byte bStack_26;
  int iStack_24;
  
  iStack_24 = 4;
  uVar2 = 0;
  __dest = param_2;
  while( true ) {
    iVar1 = iStack_24;
    iVar3 = r_nvds_walk_tag(iStack_24,&uStack_28,&iStack_24);
    if (iVar3 != 0) break;
    if ((bStack_27 & 5) == 4) {
      uVar2 = uVar2 + bStack_26 + 3;
      if (param_1 < uVar2) {
        r_assert_err("nvds.c",0x20c);
      }
      memcpy(__dest,&uStack_28,3);
      (*nvds_env)(iVar1 + 3,bStack_26,(int)__dest + 3,nvds_env);
      __dest = (void *)((int)__dest + 3 + (uint)bStack_26);
    }
  }
  r_nvds_init_memory();
  (*DAT_0001069c)(4,uVar2,param_2,DAT_0001069c);
  return;
}

