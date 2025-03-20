/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> llm_adv.o -> r_llm_adv_hdl_to_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_adv_hdl_to_id(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  byte *unaff_s1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = r_sdk_config_get_opts();
    if (*(byte *)(iVar2 + 0xd) <= uVar1) break;
    puVar3 = (undefined4 *)(uVar1 * 0x44 + *(int *)(_p_llm_env + 8));
    if ((byte)(*(char *)(puVar3 + 0x10) - 1U) < 3) {
      unaff_s1 = (byte *)*puVar3;
      if (unaff_s1 == (byte *)0x0) {
        r_assert_param(uVar1,"llm_adv.c",0xc84);
      }
      if (*unaff_s1 == param_1) break;
    }
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = r_sdk_config_get_opts();
  if (uVar1 < *(byte *)(iVar2 + 0xd)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = unaff_s1;
    }
  }
  else {
    uVar1 = 0xff;
  }
  return uVar1;
}

