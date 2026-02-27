// @ts-check
import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';

export default defineConfig({
	integrations: [
		starlight({
			title: 'My Docs',
			social: [{ icon: 'github', label: 'GitHub', href: 'https://github.com/withastro/starlight' }],
			sidebar: [
				{
					label: 'Anyagok',
					autogenerate: { directory: 'anyagok' },
				},
				{
					label: 'Feladatok',
					autogenerate: { directory: 'feladatok' },
				},
			],
		}),
	],
});
