/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_task.o -> config_llm_msg_handler_tab_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void config_llm_msg_handler_tab_reset(void)

{
  uint uVar1;
  short *psVar2;
  void *__src;
  int iVar3;
  short *psVar4;
  
  __src = (void *)(**(code **)(_r_ip_funcs_p + 0x558))(*(code **)(_r_ip_funcs_p + 0x558));
  psVar2 = _LANCHOR0;
  memcpy(_LANCHOR0,__src,(_r_ip_funcs_p >> 0x10) << 3);
  uVar1 = _r_ip_funcs_p >> 0x10;
  psVar4 = psVar2;
  for (iVar3 = 0; iVar3 < (int)uVar1; iVar3 = iVar3 + 1) {
    if (*psVar4 == 0x209) {
      *(undefined **)(psVar4 + 2) = &lld_init_end_ind_handler_hack;
    }
    psVar4 = psVar4 + 4;
  }
  memcpy(&TASK_DESC_LLM_HACK,&TASK_DESC_LLM,0xc);
  TASK_DESC_LLM_HACK = psVar2;
  return;
}

