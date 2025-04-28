/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  undefined1 uStack_38;
  byte bStack_37;
  byte bStack_36;
  int aiStack_34 [4];
  
  aiStack_34[0] = 4;
  uVar2 = 0;
  __dest = param_2;
  while( true ) {
    iVar1 = aiStack_34[0];
    iVar3 = r_nvds_walk_tag(aiStack_34[0],&uStack_38,aiStack_34);
    if (iVar3 != 0) break;
    if ((bStack_37 & 5) == 4) {
      uVar2 = uVar2 + bStack_36 + 3;
      if (param_1 < uVar2) {
        r_assert_err("nvds.c",0x20c);
      }
      memcpy(__dest,&uStack_38,3);
      (*nvds_env)(iVar1 + 3,bStack_36,(int)__dest + 3,nvds_env);
      __dest = (void *)((int)__dest + 3 + (uint)bStack_36);
    }
  }
  r_nvds_init_memory();
  (*DAT_00010694)(4,uVar2,param_2,DAT_00010694);
  return;
}

